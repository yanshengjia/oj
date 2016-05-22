// SEUOJ #num name
// description
// created by Shengjia Yan
// 2016年5月22日 上午9:12

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

// 配置
#define LOCAL 0     // 输入输出重定向
#define SPEED 0     // cin关缓冲区同步

#define ll long long int
#define ull unsigned long long int

#define FOR(i,n) for(int i=0; i<n; i++)
#define FOR1(i,n) for(int i=1; i<=n; i++)

#define fix(x) cout<<setiosflags(ios::fixed)<<setprecision(x)

const double pi = 3.1415926535898;
const double esp = 1e-8;
const double mod = 1e9 + 7;

double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }

struct Point{ double x,y; };

int a[500][500]; // a[i][j] = edit(i,j)
// len1 = str1.size()
// len2 = str2.size()
double stringSimilarity(string str1, string str2, int len1, int len2)
{
    double max;

    if(len1>len2) max = (double)len1;
    else max = (double)len2;

    a[0][0] = 0; // if i==0 && j==0, edit(i,j) = 0

    for(int i=1; i<=len1; i++) // if i>0 && j==0, edit(i,j) = i
        a[i][0] = i;
    for(int j=1; j<=len2; j++) // if i==0 && j>0, edit(i,j) = j
        a[0][j] = j;

    if(!len1 || !len2)
    {
        return 1.0-(double)a[len1][len2]/max; // 有字符串长度为0
    }

    // 字符串长度都超过0
    int min;
    for(int i=1; i<=len1; i++)
    {
        for(int j=1; j<=len2; j++)
        {
        int t1 = a[i-1][j] + 1;
        int t2 = a[i][j-1] + 1;
        t1<=t2 ? min = t1 : min = t2;
        int t3 = str1[i-1] == str2[j-1] ? a[i-1][j-1] : a[i-1][j-1] + 1;
        if(t3<min) min = t3;

        a[i][j] = min;
        }
    }

    return 1.0-(double)a[len1][len2]/max;
}

int main()
{
    // Coding The World!
    int T;
    cin>>T;
    getchar();
    
    
    string chinese = "ZaimouyicidebisaizhongshiyilangfaxianleyidaohenhaowandetiyaoqiucansaixuanshoubianxiechengxulaishibieyijuhuaweizhongwenpinyinxibanyayuhuoshiyingyuShiyilangjuedezhedaotiyouhenduozhongbanfanenggoujiejuehaoqidetaxiangkankannimenyounaxiejiefa";
    string spanish = "ElidiomaespañolocastellanoesunalenguaromanceprocedentedellatínvulgarPertenecealgrupoibéricoyesoriginariadeCastillaunaregiónhistóricadelapenínsulaibéricaenlaactualEspañaSeconocetambiénporelamericanismocoloquialcastillanotacomúnenáreasruraleseindígenasentreMéxicoylaPatagonia";
    string english = "Englishusesstrangespellingwhenwritten.DifferentwordscanusethesamelettersandcombinationsforverydifferentsoundsManyEnglishspeakingcountriesspellwordsdifferentlyThereisadifferencebetweensomespellingsinAmericaontheonehandandontheotherhandtheUnitedKingdomandmanyothercountrieswhereEnglishisthemainlanguage";
    
    
    double score_chinese;
    double score_spanish;
    double score_english;
    int len_chinese = chinese.size();
    int len_spanish = spanish.size();
    int len_english = english.size();
    int count_chinese = 73;
    int count_spanish = 232;
    int count_english = 377;
    
    string chinese_stopword[] = {
        "de", "de", "le", "zai", "shi", "wo", "you", "he", "jiu",  
        "bu", "ren", "dou", "yi", "ci", "ge", "shang", "ye", "hen", "dao", "shuo", "yao", "qu", "ni",  
        "hui", "zhe", "mei", "kan", "hao", "zi", "ji","zhong", "wen",
        
        "mou","bi","xian","wan","qiu","can","sai","xuan","shou","bian","xie","cheng",
        "xu","lai","bie","ju","hua","wei","pin","yin","xi","ya","yu","huo",
        "yingyu","lang","dao","ti","duo","ban","fa","neng","gou","jie","jue","qi","ta","xiang","men","na"
    };
    
    string spanish_stopword[] = {
    "un","una","unas","unos","uno","sobre","todo","también","tras","otro","algún","alguno","alguna","algunos","algunas","ser","es","soy","eres","somos","sois","estoy","esta","estamos","estais","estan","como","en","para","atras","porque","por","qué","estado","estaba","ante","antes","siendo","ambos","pero","por","poder","puede","puedo","podemos","podeis","pueden","fui","fue","fuimos","fueron","hacer","hago","hace","hacemos","haceis","hacen","cada","fin","incluso","primero","desde","conseguir","consigo","consigue","consigues","conseguimos","consiguen","ir","voy","va","vamos","vais","van","vaya","gueno","ha","tener","tengo","tiene","tenemos","teneis","tienen","el","la","lo","las","los","su","aqui","mio","tuyo","ellos","ellas","nos","nosotros","vosotros","vosotras","si","dentro","solo","solamente","saber","sabes","sabe","sabemos","sabeis","saben","ultimo","largo","bastante","haces","muchos","aquellos","aquellas","sus","entonces","tiempo","verdad","verdadero","verdadera","cierto","ciertos","cierta","ciertas","intentar","intento","intenta","intentas","intentamos","intentais","intentan","dos","bajo","arriba","encima","usar","uso","usas","usa","usamos","usais","usan","emplear","empleo","empleas","emplean","ampleamos","empleais","valor","muy","era","eras","eramos","eran","modo","bien","cual","cuando","donde","mientras","quien","con","entre","sin","trabajo","trabajar","trabajas","trabaja","trabajamos","trabajais","trabajan","podria","podrias","podriamos","podrian","podriais","yo","aquel",
    
    "el","idioma","español","o","castellano","es","una","lengua","romance","procedente","del","latín","vulgar","pertenece","al","grupo","ibérico","y","es","originaria","de","Castilla","una","región","histórica","de","la","península","ibérica","en","la","actual","españa","Se","conoce","también","por","el","americanismo","coloquial","castilla","nota","común","en","áreas","rurales","e","indígenas","entre","México","y","la","patagonia"
    }; 

    string english_stopword[] = {
    "english", "a", "about", "above", "above", "across", "after", "afterwards", "again", "against", "all", "almost", "alone", "along", "already", "also","although","always","am","among", "amongst", "amoungst", "amount",  "an", "and", "another", "any","anyhow","anyone","anything","anyway", "anywhere", "are", "around", "as",  "at", "back","be","became", "because","become","becomes", "becoming", "been", "before", "beforehand", "behind", "being", "below", "beside", "besides", "between", "beyond", "bill", "both", "bottom","but", "by", "call", "can", "cannot", "cant", "co", "con", "could", "couldnt", "cry", "de", "describe", "detail", "do", "done", "down", "due", "during", "each", "eg", "eight", "either", "eleven","else", "elsewhere", "empty", "enough", "etc", "even", "ever", "every", "everyone", "everything", "everywhere", "except", "few", "fifteen", "fify", "fill", "find", "fire", "first", "five", "for", "former", "formerly", "forty", "found", "four", "from", "front", "full", "further", "get", "give", "go", "had", "has", "hasnt", "have", "he", "hence", "her", "here", "hereafter", "hereby", "herein", "hereupon", "hers", "herself", "him", "himself", "his", "how", "however", "hundred", "ie", "if", "in", "inc", "indeed", "interest", "into", "is", "it", "its", "itself", "keep", "last", "latter", "latterly", "least", "less", "ltd", "made", "many", "may", "me", "meanwhile", "might", "mill", "mine", "more", "moreover", "most", "mostly", "move", "much", "must", "my", "myself", "name", "namely", "neither", "never", "nevertheless", "next", "nine", "no", "nobody", "none", "noone", "nor", "not", "nothing", "now", "nowhere", "of", "off", "often", "on", "once", "one", "only", "onto", "or", "other", "others", "otherwise", "our", "ours", "ourselves", "out", "over", "own","part", "per", "perhaps", "please", "put", "rather", "re", "same", "see", "seem", "seemed", "seeming", "seems", "serious", "several", "she", "should", "show", "side", "since", "sincere", "six", "sixty", "so", "some", "somehow", "someone", "something", "sometime", "sometimes", "somewhere", "still", "such", "system", "take", "ten", "than", "that", "the", "their", "them", "themselves", "then", "thence", "there", "thereafter", "thereby", "therefore", "therein", "thereupon", "these", "they", "thickv", "thin", "third", "this", "those", "though", "three", "through", "throughout", "thru", "thus", "to", "together", "too", "top", "toward", "towards", "twelve", "twenty", "two", "un", "under", "until", "up", "upon", "us", "very", "via", "was", "we", "well", "were", "what", "whatever", "when", "whence", "whenever", "where", "whereafter", "whereas", "whereby", "wherein", "whereupon", "wherever", "whether", "which", "while", "whither", "who", "whoever", "whole", "whom", "whose", "why", "will", "with", "within", "without", "would", "yet", "you", "your", "yours", "yourself", "yourselves", "the",
    
    "english","uses","strange","spelling","when","written","different","words","can","use","the","same","letters","and","combinations","for","very","different","sounds","many","english","speaking","countries","spell","words","differently","there","is","a","difference","between","some","spellings","in","america","on","the","one","hand","and","on","the","other","hand","the","United","Kingdom","and","many","other","countries","where","English","is","the","main","language"
    };
    
    stringstream ss;
    string str;
    
    while(getline(cin, str))
    {
        ss.clear();
        score_chinese = 0.0;
        score_spanish = 0.0;
        score_english = 0.0;
        
        int len_str = str.size();
        score_chinese += stringSimilarity(str, chinese, len_str, len_chinese);
        score_spanish += stringSimilarity(str, spanish, len_str, len_spanish);
        score_english += stringSimilarity(str, english, len_str, len_english);
        
        ss<<str;
        
        string mention;
        
        while(ss>>mention)
        {
            int len_mention = mention.size();
            
            for(int i=0; i<count_chinese; i++)
            {
                if(mention == chinese_stopword[i]) score_chinese += 1;
                int len_chinese_stopword = chinese_stopword[i].size();
                score_chinese += stringSimilarity(mention, chinese_stopword[i], len_mention, len_chinese_stopword);
            }
            
            for(int i=0; i<count_spanish; i++)
            {
                if(mention == spanish_stopword[i]) score_spanish += 1;
                int len_spanish_stopword = spanish_stopword[i].size();
                score_spanish += stringSimilarity(mention, spanish_stopword[i], len_mention, len_spanish_stopword);
            }
            
            for(int i=0; i<count_english; i++)
            {
                if(mention == english_stopword[i]) score_english += 1;
                int len_english_stopword = english_stopword[i].size();
                score_english += stringSimilarity(mention, english_stopword[i], len_mention, len_english_stopword);
            }
        }
       
        
        double score = score_chinese;
        string ans = "Chinese Pinyin";
        
        if(score_spanish > score)
        {
            score = score_spanish;
            ans = "Spanish";
        }
        if(score_english > score)
        {
            score = score_english;
            ans = "English";
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}