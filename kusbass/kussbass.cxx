#encoding "utf-8"
#GRAMMAR_ROOT S

//Параметры принимающие значение только Есть или Нет, можно объединить в одну большую группу
//GrassBunker -> Word<kwtype="слово_травозборник"> interp (Param.Name) (Hyphen) Word<kwtype="слово_травозборник_контент"> interp (Param.Value::not_norm);
//Mulchirov -> Word<kwtype="слово_мульчирование"> interp (Param.Name) (Hyphen) Word<kwtype="слово_мульчирование_контент"> interp (Param.Value::not_norm);
//Autostart -> Word<kwtype="слово_автозапуск"> interp (Param.Name) (Hyphen) Word<kwtype="слово_автозапуск_контент"> interp (Param.Value::not_norm);
//Samohod -> Word<kwtype="слово_cамоходная"> interp (Param.Name) (Hyphen) Word<kwtype="слово_cамоходная_контент"> interp (Param.Value::not_norm);
//BigWheel -> Word<kwtype="слово_bigwheel"> interp (Param.Name) (Hyphen) Word<kwtype="слово_bigwheel_контент"> interp (Param.Value::not_norm);

//Общая грамматики на Есть Нет
GeberalYesNo -> Word<kwtype="слово_общая_да_нет"> interp (Param.Name::not_norm) (Hyphen) Word<kwtype="слово_общая_да_нет_контент"> interp (Param.Value::not_norm);

//Мощность можно разбить на две цепочки
Power -> Word<kwtype="слово_мощность"> interp (Param.Name) (Comma) (Colon) (Word<kwtype="слово_мощность_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value) (Word<kwtype="слово_мощность_ед_измер"> interp (Param.Unit));

Massa -> Word<kwtype="слово_масса"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_масса_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);
Massa -> Word<kwtype="слово_масса"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_масса_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+г/> interp (Param.Value);

Voltage -> Word<kwtype="слово_напряжение"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_напряжение_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+В/> interp (Param.Value);
Voltage -> Word<kwtype="слово_напряжение"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_напряжение_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);

//дописать постфикс на регулярках 
Proizvod -> Word<kwtype="слово_производительность"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_напряжение_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) AnyWord interp (Param.Value); 

Diamentr -> Word<kwtype="слово_диаметр"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_диаметр_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);

Privod -> Word<kwtype="слово_привод"> interp (Param.Name) (Hyphen) Word<kwtype="слово_привод_контент"> interp (Param.Value::not_norm);

Napor -> Word<kwtype="слово_напор"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_напор_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);

//Добавить регулярные выражения
Size -> Word<kwtype="слово_размер"> interp (Param.Name) (Comma) (Colon) (Hyphen) AnyWord interp (Param.Value) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_размер_ед_измер"> interp (Param.Unit));
Size -> Word<kwtype="слово_размер"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_размер_ед_измер"> interp (Param.Unit)) (Comma) (Colon) (Hyphen) AnyWord interp (Param.Value);

KrutMom -> Word<kwtype="слово_крут_момент"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_крут_момент_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);

Ploshad -> Word<kwtype="слово_площадь"> interp (Param.Name) (Comma) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);
Ploshad -> Word<kwtype="слово_площадь"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_площадь_ед_измер"> interp (Param.Unit)) (Comma) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);

EngineV -> Word<kwtype="слово_объем_двигателя"> interp (Param.Name) (Comma) (Colon) (Hyphen) (AnyWord interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);

Width -> Word<kwtype="слово_ширина"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_ширина_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);

Tok -> Word<kwtype="слово_ток"> interp (Param.Name) (Comma) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+А/> interp (Param.Value);

//Oborot -> Word<kwtype="слово_обороты"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_обороты_ед_измер"> interp (Param.Unit)) (Comma) (Colon) (Hyphen) AnyWord interp (Param.Value);

S -> GeberalYesNo;
S -> Power;
S -> Massa;
S -> Napor;
S -> Voltage;
S -> Proizvod;
S -> Diamentr;
S -> Privod;
S -> Size;
S -> KrutMom;
S -> Ploshad;
S -> EngineV;
S -> Width;
S -> Tok;
//S -> Oborot;

