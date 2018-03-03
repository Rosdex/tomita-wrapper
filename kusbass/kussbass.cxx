#encoding "utf-8"
#GRAMMAR_ROOT S

//Параметры принимающие значение только Есть или Нет, можно объединить в одну большую группу
//GrassBunker -> Word<kwtype="слово_травозборник"> interp (Param.Name) (Hyphen) Word<kwtype="слово_травозборник_контент"> interp (Param.Value::not_norm);
//Mulchirov -> Word<kwtype="слово_мульчирование"> interp (Param.Name) (Hyphen) Word<kwtype="слово_мульчирование_контент"> interp (Param.Value::not_norm);
//Autostart -> Word<kwtype="слово_автозапуск"> interp (Param.Name) (Hyphen) Word<kwtype="слово_автозапуск_контент"> interp (Param.Value::not_norm);
//Samohod -> Word<kwtype="слово_cамоходная"> interp (Param.Name) (Hyphen) Word<kwtype="слово_cамоходная_контент"> interp (Param.Value::not_norm);
//BigWheel -> Word<kwtype="слово_bigwheel"> interp (Param.Name) (Hyphen) Word<kwtype="слово_bigwheel_контент"> interp (Param.Value::not_norm);

//Общая грамматики на Есть Нет
GeberalYesNo -> Word<kwtype="слово_общая_да_нет"> interp (Param.Name) (Hyphen) Word<kwtype="слово_общая_да_нет_контент"> interp (Param.Value::not_norm);

//Мощность можно разбить на две цепочки

Power -> Word<kwtype="слово_мощность"> interp (Param.Name) (Comma) (Colon) (Word<kwtype="слово_мощность_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value) (Word<kwtype="слово_мощность_ед_измер"> interp (Param.Unit));

Massa -> Word<kwtype="слово_масса"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_масса_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);
Massa -> Word<kwtype="слово_масса"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_масса_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+г/> interp (Param.Value);

Voltage -> Word<kwtype="слово_напряжение"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_напряжение_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+В/> interp (Param.Value);
Voltage -> Word<kwtype="слово_напряжение"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_напряжение_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);

Napor -> Word<kwtype="слово_напор"> interp (Param.Name) (Comma) (Colon) (Hyphen) (Word<kwtype="слово_напор_ед_измер"> interp (Param.Unit)) (Colon) (Hyphen) Word<wfm=/[0-9]*[.,]?[0-9]+/> interp (Param.Value);


//S -> GrassBunker;
//S -> Mulchirov;
//S -> Autostart;
//S -> Samohod;
//S -> BigWheel;
S -> GeberalYesNo;

S -> Power;
S -> Massa;
S -> Napor;
S -> Voltage;

