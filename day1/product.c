#include <stdio.h>
#define N 10000

int main(void){
  //char DATA[] = "1299876140";
  char DATA [N+1] = "\
43125608879540058090285745082171601981796711808462\
12669324707559726070596752701143084811746995542462\
52633540527154843613060201763948389923545753723562\
27339838846296072372340309631292478687642584127824\
81774655325421414110452012883744532762954224967388\
00119288641400186609779686112630376439834376636881\
81880569831555913324451935955269922960968851172792\
58287389554068576764824031125178613020371120550596\
98815649890351600316022523648589075040925185037398\
83579476624461826836350352089437002176912188106658\
89668313083728705120251027292163977603535349291541\
48978952260226364584616902612068237317380965441948\
00310576608126196622472050154965227744937827845537\
43093050545818038903769530811057725478152375658805\
88255235100590639558715288222156861576251784563468\
07646753212310296199052637429433032942289044771350\
45464594572514931140149032085441844239983032169788\
79412022221793307267433395252998238782441902888199\
99836849380795966438029318015629514629006542463975\
92872025143384587073756154481895894276732479554786\
75364334884894830882509498501623047508254286267672\
37460107853345855378699463186403391185936368245928\
41466350713321620736216669671859733180134899690719\
14439799051424829967813168498393636102763804334700\
43469580742037484615660227059418988860768593235524\
09364747414288423272956473286210934612115810892259\
43994021677719138566551871533565980449318255287860\
89038251999052398545702375832027247534388723367540\
77262243914818938730333885929042387486303395760044\
75324755219359470924461421255021693188933253720357\
39993998809052662890739793730716362665448517416769\
61712823345746875403714059736545011104076281787346\
27193765964689528804957111226168269987170702310873\
50592925785069155633946328502902362974924795535210\
63996346417665152942077572542053578654697759504856\
63631410361594951774184819524284565242620805881876\
10007616616277461822654477736911122881461331702487\
27196406040744517262390694474241225887108348962863\
15804661171136041626840882310253820698951010324994\
16414423559176364424801279134983670574560583095960\
10619997889355884213902475557135225531595071522380\
83671469842220985618595324053185515171798329814243\
26054928359420437440761041018058095984118319035468\
64095498107579462341001306838969076867016893165062\
77549403965465338426393800966599467918175149593083\
25957807588363273943144495804321985543262277238575\
21799740331119936003110575575069664763085859740342\
70532393828625136388200917276624355485485913355186\
13903031964635666353747896833830033644692688016046\
13048057749953731738870132232999817104529858927116\
10857903210180882715109272369453540219296795836775\
72067700073579690728257559852043758834085391883157\
60597346750278342030203725790486262698756286670923\
86635811169733334068597923655497046767673950296547\
74375433831844680579757615233155902172413094918996\
34937356563057559996827247420613748747709366656030\
38333859528193438783837408808643603248235726264668\
66909044382657365337480460448804606425521063454758\
88063276323392829891228502288276352772485391730391\
92712088336152538534781302914267631745520515730152\
00003796092479594859637068653238180654287179577580\
25169229709172004222980592125654993473605480477164\
37891655905397320951983275718801643132150580623771\
22008701252069694320076938735239019028768374460526\
52409758070954272404403908818652031276473531214112\
44452521167182240348264618208293522219400258429210\
22250099687320854414010326091867545186622312713140\
74353056357807314527311735671202218188657861059436\
87891912336446148116151777748427082465510568404258\
59759877225031631142869254735709892624820669953964\
15297033364514673614443271169554385273854262221937\
83139759379135747334964705667166069710659582256182\
75661015341516449428444576111379681748535996977324\
54776970037048180729040042670298123780735135764005\
50522308559895015447593705676176846617077328624156\
62847725258388911491668980328969351482162850429459\
62758430132143984050541150412759327270623321314568\
65901857148231003356907023295923670246594191855997\
26551668327374718593596749891748713841261753055708\
70646192795624334157419736464433399401574198671613\
95960302933246834533933021331121698903635996762615\
00852797243644682906919431401077582012628751509624\
78090573119983283687279524548980322555297959021114\
88156937526146260207453135967499367717125558030447\
85911016467307573140313200278407799717054632672086\
94346322376229691245631421390933374827105158134539\
56663188811610368201021757673231605621318152652259\
00983406984913906179308760962007787816521548695966\
91033122042057493565857135827691068144984077289027\
23820289998485899540794429404049614239399624508016\
27237524346568470440427384502491640061843513257611\
13878101309886324156510980014156850563140926080694\
31599893222417725040655803926927102470739328611997\
80780596375492446270451116534706599515916368743471\
31850710921451553907844445785548726023231296728795\
54757386608427429145482669245158250119054445934881\
26014156894870989134776780206247567636841892400135\
70090587074721002029779818578653465351268638264275\
08516465693962433772137149507567866818825604715936\
28314168187932896294878490010947023749596472992222\
34867923664841059677935188345103361255874560339404\
41002019437634204974165154386620719592213868905821\
66237610529284451616979094851452171935970009569657\
83398176585223507357617320906791030254579290635277\
13826361573638005451584817688021876304295470088370\
98788162073448123712037750086734187358503774214560\
92558300640024999433368189250398225221406590822700\
64492829052849245779586923864896308847320550701156\
61256275016016476645606794778870560320793204715412\
02311686470441574627537036299903909357877813137093\
72753529487004628411249305055731812640980405718051\
51619627444756721281302021629785618823289058192555\
72993454586223836858064352905368484919674865707968\
28240453221849799004488767492681983117968454455295\
83487747938097348458477458862913790596767765036234\
68411025890884522002464589667582026441794297823585\
72406425379063852338394130359576333301678727589086\
09245460656986425943833533405239122530688254810214\
12650704857316674162988919459949737146145355424184\
99394802528720212065466829988314671614264009068164\
57106777423157005577430447500702283506119419176378\
59662184220767358195915227069473986038787284325067\
97878514034111047229075387568230281103862603324553\
15977562266503017012148607755695778339718713181238\
67440513678627271587895772808663216800793974012512\
26924294509379335052457934071357429546862848838228\
18395749116634499769945232391041685643594492478797\
34717204524607771517694422342268643919756713555381\
20992667383078723636695006319686054554403178076324\
36784856319125578008865418232418569938726470858399\
99858431572644651219960008643597554674326539169426\
74906534552748710989723254651420411202000836261542\
64185709521327445194298665178350611700349229143092\
93278661699192433708455674556362338784419518198118\
98340896120245523867967215643965048642062440570584\
38438074644019869333589479068193114086811355763420\
23290402717861064460948584503409128223533226870024\
76014880239058549734098463504126385910690690051359\
19250438789739425362253677465871539366023597629070\
01526640442001084597893688883439561696747761767328\
85672525637002375204466707503746922146628243666471\
02649841998667717823830939231984985073779517906303\
32704093488813401276184006692905405622340714932016\
46645146187937434615841064956644736513397215135554\
11769282527575531487041045858585091277022707671407\
96013363909998727799588897606688943343356311373287\
03451143080544136037611611717823873708378104438670\
97914575104257579009247250126609581075696153052847\
11487766624320795765392932984633984970562210614894\
82318848473450398675738384391338099866779517273046\
64923459299954997777360779592503788227939242151311\
68475758248061422064173691551223846140976592014004\
94180747403642586738119013148152285481986576044644\
84389320538760218116035624557969335765012737048134\
39582935681046151072435355308059850717085705593009\
68660350276795864142180908061850150883576688506592\
20774047767567278943534974028502717976167273247032\
15041778581145856939456222518061039062481445504625\
68159224944176563413980321076843298508394680726370\
35204213815201824747041654176542161133580588919083\
27193511510747278813297419999508343850654397357078\
93380550837399527245689711500007158964011228413006\
13369682059756151374997758197877705789059929047033\
21962860834420508803088546644370077292731534308192\
31511791360459053714935288623502064020586185068465\
98349817804831286291697276493541943529732195790523\
66401596166977954428580872163232203190462634700945\
65410044168689597918607980944019095457431546733570\
08298941874846667699581495970279411280580156046063\
38445600085101614821764903800985413331102915806280\
85823507495628847467201354647762542516018279624231\
88887630854471261164054898473465200387702068311349\
32719746414567823810448541186626720444187935862947\
82520859915311218578672770901693383473754854624667\
84400555302780296877582047204376687417856274445991\
68679690410983985797237145343293036116906619253100\
33574786253841432516141281053305461389460009222566\
74648790422623796605721574983170834251564347550492\
20385841689926453039873711307354539701156232401068\
71116967980013111972430026897316406854606458764893\
45769425187745141971832780145449813467454752882270\
29482751399862420475985317597755658099150561804841\
33770782693651918574033035406425171301757021204651\
90640091205150657177126808476988099325317933813978\
18526787956300962912025713174590574059226307367644\
11974736044742307574440380292127071413792873369186\
94995915716802685497658207525172056395380263392637\
25935628773124886579234190042672152793207732471875\
75399468405807501575567884507966428060137196785219\
12363438824300838795783327809198341423137979050778\
05761811175975226641056849346365664349537545291818\
32750241919846520263089805619506254056592253614915\
13015721469992024779408327511099871360023951332993\
25384032391293345628819147088301211530846835709847\
41218795219694449612006911584000109044600758325137\
95552017693951540280241751270846221837214358359123\
42367332052027854749933142041279926630168109969663\
50231403960081417220700514850600686246792672328531\
01789986333716305837439594052845263336629195918399\
68379989136305647728891543468851273060734695091282\
";
  int L = 10;
  int max = 0;
  int product;
  int i,j;
  for(i=0; i + L <= N; i++){
    product = 1;
    for(j=0; j <= L - 1; j++){
      //printf("%d %d\n",j,DATA[i+j] - 48);
      product *= (DATA[i+j] -48);//convert char to int by subtracting 48
    }
    //printf("%d\n",product);
    if(product >  max) {max = product;}
  }
  printf("%d\n",max);
}