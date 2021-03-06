#include <string.h>
#include "country.h"

struct country country_code[263]={ /* country_code est une var global */
      {"AA","Aruba"},
      {"AC","Antigua et Barbuda"},
      {"AE","Emirats arabes unis"},
      {"AF","Afghanistan"},
      {"AG","Algerie"},
      {"AJ","Azerbaidjan"},
      {"AL","Albanie"},
      {"AM","Arm�nie"},
      {"AN","Andorre"},
      {"AO","Angola"},
      {"AQ","Samoa americaines"},
      {"AR","Argentine"},
      {"AS","Australie"},
      {"AT","Iles Ashmore et Cartier"},
      {"AU","Autriche"},
      {"AV","Anguilla"},
      {"AY","Antarctique"},
      {"BA","Bahrein"},
      {"BB","Barbade"},
      {"BC","Botswana"},
      {"BD","Bermudes"},
      {"BE","Belgique"},
      {"BF","Bahamas"},
      {"BG","Bangladesh"},
      {"BH","Belize"},
      {"BK","Bosnie-Herzegovine"},
      {"BL","Bolivie"},
      {"BM","Birmanie"},
      {"BN","B�nin"},
      {"BO","Bi�lorussie"},
      {"BP","Iles Salomon"},
      {"BQ","Ile de la Navasse"},
      {"BR","Br�sil"},
      {"BS","Bassas da India"},
      {"BT","Bhoutan"},
      {"BU","Bulgarie"},
      {"BV","Ile Bouvet"},
      {"BX","Brunei"},
      {"BY","Burundi"},
      {"CA","Canada"},
      {"CB","Cambodge"},
      {"CD","Tchad"},
      {"CE","Sri Lanka"},
      {"CF","Republique du Congo"},
      {"CG","Republique democratique du Congo"},
      {"CH","Republique populaire de Chine"},
      {"CI","Chili"},
      {"CJ","Iles Caiimans"},
      {"CK","Iles Cocos"},
      {"CM","Cameroun"},
      {"CN","Comores"},
      {"CO","Colombie"},
      {"CQ","Iles Mariannes du Nord"},
      {"CR","Iles de la Mer de Corail"},
      {"CS","Costa Rica"},
      {"CT","Republique centrafricaine"},
      {"CU","Cuba"},
      {"CV","Cap-Vert"},
      {"CW","Iles Cook"},
      {"CY","Chypre"},
      {"DA","Danemark"},
      {"DJ","Djibouti"},
      {"DO","Dominique"},
      {"DQ","Ile Jarvis"},
      {"DR","Republique dominicaine"},
      {"EC","Equateur"},
      {"EG","Egypte"},
      {"EI","Irlande"},
      {"EK","Guinee equatoriale"},
      {"EN","Estonie"},
      {"ER","Erythree"},
      {"ES","Salvador"},
      {"ET","Ethiopie"},
      {"EU","Ile Europa"},
      {"EZ","Republique tcheque"},
      {"FG","Guyane Francaise"},
      {"FI","Finlande"},
      {"FJ","Fidji"},
      {"FK","Iles Falkland Malouines"},
      {"FM","Micronesie"},
      {"FO","Iles Feroe"},
      {"FP","Polynesie francaise"},
      {"FQ","Ile Baker"},
      {"FR","France"},
      {"FS","Terres australes et antarctiques francaises"},
      {"GA","Gambie"},
      {"GB","Gabon"},
      {"GG","Georgie"},
      {"GH","Ghana"},
      {"GI","Gibraltar"},
      {"GJ","Grenade"},
      {"GK","Guernesey"},
      {"GL","Groenland"},
      {"GM","Allemagne"},
      {"GO","Iles Glorieuses"},
      {"GP","Guadeloupe"},
      {"GQ","Guam"},
      {"GR","Grece"},
      {"GT","Guatemala"},
      {"GV","Guinee"},
      {"GY","Guyana"},
      {"GZ","Bande de Gaza"},
      {"HA","Haiti"},
      {"HK","Hong Kong"},
      {"HM","Iles Heard-et-MacDonald"},
      {"HO","Honduras"},
      {"HQ","Ile Howland"},
      {"HR","Croatie"},
      {"HU","Hongrie"},
      {"IC","Islande"},
      {"ID","Indonesie"},
      {"IM","Ile de Man"},
      {"IN","Inde"},
      {"IO","Territoire britannique de l'ocean Indien"},
      {"IP","Ile de Clipperton"},
      {"IR","Iran"},
      {"IS","Israel"},
      {"IT","Italie"},
      {"IV","C�te d'Ivoire"},
      {"IZ","Iraq"},
      {"JA","Japon"},
      {"JE","Jersey"},
      {"JM","Jamaique"},
      {"JN","Ile Jan Mayen"},
      {"JO","Jordanie"},
      {"JQ","Atoll Johnston"},
      {"JU","Ile Juan de Nova"},
      {"KE","Kenya"},
      {"KG","Kirghizistan"},
      {"KN","Coree du Nord"},
      {"KQ","Recif Kingman"},
      {"KR","Kiribati"},
      {"KS","Coree du Sud"},
      {"KT","Ile Christmas"},
      {"KU","Koweit"},
      {"KV","Kosovo"},
      {"KZ","Kazakhstan"},
      {"LA","Laos"},
      {"LE","Liban"},
      {"LG","Lettonie"},
      {"LH","Lituanie"},
      {"LI","Liberia"},
      {"LO","Slovaquie"},
      {"LS","Liechtenstein"},
      {"LT","Lesotho"},
      {"LU","Luxembourg"},
      {"LY","Libye"},
      {"MA","Madagascar"},
      {"MB","Martinique"},
      {"MC","Macao"},
      {"MD","Moldavie"},
      {"MF","Mayotte"},
      {"MG","Mongolie"},
      {"MH","Montserrat"},
      {"MI","Malawi"},
      {"MJ","Montenegro"},
      {"MK","Macedoine"},
      {"ML","Mali"},
      {"MN","Monaco"},
      {"MO","Maroc"},
      {"MP","Maurice"},
      {"MQ","Iles Midway"},
      {"MR","Mauritanie"},
      {"MT","Malte"},
      {"MU","Oman"},
      {"MV","Maldives"},
      {"MX","Mexique"},
      {"MY","Malaisie"},
      {"MZ","Mozambique"},
      {"NC","Nouvelle-Caledonie"},
      {"NE","Niue"},
      {"NF","Ile Norfolk"},
      {"NG","Niger"},
      {"NH","Vanuatu"},
      {"NI","Nigeria"},
      {"NL","Pays-Bas"},
      {"NO","Norvege"},
      {"NP","Nepal"},
      {"NR","Nauru"},
      {"NS","Suriname"},
      {"NT","Antilles neerlandaises"},
      {"NU","Nicaragua"},
      {"NZ","Nouvelle-Zelande"},
      {"PA","Paraguay"},
      {"PC","Iles Pitcairn"},
      {"PE","Perou"},
      {"PF","Iles Paracel"},
      {"PG","Iles Spratley"},
      {"PK","Pakistan"},
      {"PL","Pologne"},
      {"PM","Panama"},
      {"PO","Portugal"},
      {"PP","Papouasie-Nouvelle-Guinee"},
      {"PS","Palaos"},
      {"PU","Guinee-Bissao"},
      {"QQ","Qatar"},
      {"RE","Reunion"},
      {"RM","Iles Marshall"},
      {"RO","Roumanie"},
      {"RP","Philippines"},
      {"PR","Porto Rico"},
      {"RS","Russie"},
      {"RW","Rwanda"},
      {"SA","Arabie saoudite"},
      {"SB","Saint-Pierre-et-Miquelon"},
      {"SC","Saint-Christophe-et-Nieves"},
      {"SE","Seychelles"},
      {"SF","Afrique du Sud"},
      {"SG","Senegal"},
      {"SH","Sainte-Helene"},
      {"SI","Slovenie"},
      {"SL","Sierra Leone"},
      {"SM","Saint-Marin"},
      {"SN","Singapour"},
      {"SO","Somalie"},
      {"SP","Espagne"},
      {"ST","Sainte-Lucie"},
      {"SU","Soudan"},
      {"SV","Svalbard"},
      {"SW","Suede"},
      {"SX","Georgie du Sud-et-les Iles Sandwich du Sud"},
      {"SY","Syrie"},
      {"SZ","Suisse"},
      {"TD","Trinite-et-Tobago"},
      {"TE","Ile Tromelin"},
      {"TH","Thailande"},
      {"TI","Tadjikistan"},
      {"TK","Iles Turques et Caiques"},
      {"TL","Tokelau"},
      {"TN","Tonga"},
      {"TO","Togo"},
      {"TP","Sao Tome-et-Principe"},
      {"TS","Tunisie"},
      {"TT","Timor-Leste mise � jour FIPS 104�"},
      {"TU","Turquie"},
      {"TV","Tuvalu"},
      {"TW","Republique de Chine Taiwan"},
      {"TX","Turkmenistan"},
      {"TZ","Tanzanie"},
      {"UG","Ouganda"},
      {"UK","Royaume-Uni"},
      {"UP","Ukraine"},
      {"US","Etats-Unis"},
      {"UV","Burkina"},
      {"UY","Uruguay"},
      {"UZ","Ouzbekistan"},
      {"VC","Saint-Vincent-et-les Grenadines"},
      {"VE","Venezuela"},
      {"VI","Iles Vierges britanniques"},
      {"VM","Vietnam"},
      {"VQ","Iles Vierges americaines"},
      {"VT","Vatican"},
      {"WA","Namibie"},
      {"WE","Cisjordanie"},
      {"WF","Iles Wallis-et-Futuna"},
      {"WI","Sahara Occidental"},
      {"WQ","Wake"},
      {"WS","Samoa occidentales"},
      {"WZ","Swaziland"},
      {"YI","Serbie et Montenegro"},
      {"YM","Yemen"},
      {"ZA","Zambie"},
      {"ZI","Zimbabwe"}
};

int country_alias2code(char *alias){
    int i; for(i=0;i<=262;i++)
        if(!strcmp(alias,country_code[i].alias))
            return i+1;
    return -1;
}

const char *country_alias2name(char *alias){
    int i; for(i=0;i<=262;i++)
        if(!strcmp(alias,country_code[i].alias))
            return country_code[i].name;
    return NULL;
}

int country_name2code(char *name){
    int i; for(i=0;i<=262;i++)
        if(!strcmp(name,country_code[i].name))
            return i+1;
    return -1;
}

const char *country_name2alias(char *name){
    int i; for(i=0;i<=262;i++)
        if(!strcmp(name,country_code[i].name))
            return country_code[i].alias;
    return NULL;
}

const char *country_code2name(int code){
    return country_code[code-1].name;
}

const char *country_code2alias(int code){
    return country_code[code-1].alias;
}
