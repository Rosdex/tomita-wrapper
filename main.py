# -*- encoding: utf-8 -*-
import os
import subprocess
import xml.etree.ElementTree as ElementTree
import json

def read_dataset(filename):
    offers = []
    data = json.load(open(filename, encoding='utf8'))
    return data 
    
def show_facts(facts):
    for fact in facts:
        print("{0} {1} {2}".format(fact['fact'], fact['unit'], fact['value']))
    
def save_facts(offers, filename):
    with open(filename, 'w', encoding='utf8') as file:
        for offer in offers:
            file.write("Product - {0} ".format(offer['product']))
            file.write("Company - {0} ".format(offer['company']))
            file.write('\n')
            file.write('Факты: \n')
            
            for fact in offer['facts']:
                file.write("{0} {1} {2} \n".format(fact['fact'], fact['unit'], fact['value']))
            
            file.write('------------------------------------\n')

class TomitaParser(object):
    def __init__(self, executable, config, debug=True, validate=True):
        self.debug_mode = debug
        self.debug("Init Tomita Parser...")

        self.executable = os.path.expanduser(executable)
        if not os.path.exists(self.executable):
            raise Exception("Tomita executable not found at: %s" % self.executable)

        self.debug("Executable: %s" % self.executable)

        self.config = os.path.expanduser(config)
        if not os.path.exists(self.config):
            raise Exception("Config file not found at: %s" % self.config)

        self.debug("Config: %s" % self.config)

        self.path = self.config[:self.config.rfind('\\')]

        self.debug("Path: %s" % self.path)
        self.debug("ZBS!")

        if validate:
            self.validate_config()

    def validate_config(self):
        is_xml = False
        with open(self.config, "r") as f:
            for line in f.readlines():
                line = line.strip()
                if line:
                    if line.startswith("File"):
                        raise Exception("This library uses STDIN and STDOT for communicating with Tomita Parser, "
                                        "please remove all File = \"...\" from Input and Output sections in config.")
                    if line.startswith("Format") and "xml" in line:
                        is_xml = True
        if not is_xml:
            raise Exception("This library working only with XML output, "
                            "please add \"Format = xml;\" to the Output section.")

    def run(self, text, with_facts=True, with_leads=True):
        self.debug("Running Tomita Parser...")
        
        pipe = subprocess.Popen(
            [self.executable, self.config],
            stdout=subprocess.PIPE,
            stdin=subprocess.PIPE,
            stderr=subprocess.PIPE,
            cwd=self.path
        )
        out, err = pipe.communicate(input=text.encode("utf-8"))

        self.debug(err)
        
        facts = []
        leads = []
        etree_root = ElementTree.fromstring(out)
        if etree_root.find("document") is not None:
            if with_facts:
                self.debug("Parsing facts...")
                for fact in etree_root.find("document").find("facts"):
                    # unit and val is optional fields. So we need check that they are exist
                    unit = fact.find("Unit")
                    unit = unit.attrib.get("val") if unit is not None else ''
                    
                    val = fact.find("Value")
                    val = val.attrib.get("val") if val is not None else ''
                
                    facts.append({
                        "fact_id": fact.attrib.get("FactID"),
                        "lead_id": fact.attrib.get("LeadID"),
                        "pos": fact.attrib.get("pos"),
                        "len": fact.attrib.get("len"),
                        "fact": fact.find("Name").attrib.get("val"),
                        "unit": unit,
                        "value": val,
                    })

            if with_leads:
                self.debug("Parsing leads...")
                for lead in etree_root.find("document").find("Leads"):
                    leads.append({
                        "lead_id": lead.attrib.get("id"),
                        "lead": lead.attrib.get("text")
                    })

        return facts, leads

    def debug(self, text):
        if self.debug_mode:
            print(text)
            
if __name__ == "__main__":
    dataset = read_dataset('dataset.json')
    
    offers = []
    facts = []
    leads = []
    
    for item in dataset:
        print('Handle: {0}'.format(item['name']))
        print('Company: {0}'.format(item['company']))
        print(' ')
        
        tomita = TomitaParser('C:\\Temp\\tomita\\tomitaparser.exe', 'C:\\Temp\\poor-python-yandex-tomita-parser-master\\kusbass\\config.proto', debug=False)
        facts, leads = tomita.run(item['desc'])
        show_facts(facts)
        
        offers.append({
            "product": item['name'],
            "company": item['company'],
            "facts": facts
        })
        
        print('-----------------')
        print('\n\n')
    
    save_facts(offers, 'output.txt')
    