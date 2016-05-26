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

struct Point { double x, y; };

int a[500][500]; // a[i][j] = edit(i,j)
				 // len1 = str1.size()
				 // len2 = str2.size()


double stringSimilarity(string str1, string str2, int len1, int len2)
{
	

	int a[100][100]; // a[i][j] = edit(i,j)
	double max;

	if (len1>len2) max = (double)len1;
	else max = (double)len2;

	a[0][0] = 0; // if i==0 && j==0, edit(i,j) = 0

	for (int i = 1; i <= len1; i++) // if i>0 && j==0, edit(i,j) = i
		a[i][0] = i;
	for (int j = 1; j <= len2; j++) // if i==0 && j>0, edit(i,j) = j
		a[0][j] = j;

	if (!len1 || !len2)
	{
		return 1.0 - (double)a[len1][len2] / max; // 有字符串长度为0
	}

	// 字符串长度都超过0
	int min;
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			int t1 = a[i - 1][j] + 1;
			int t2 = a[i][j - 1] + 1;
			t1 <= t2 ? min = t1 : min = t2;
			int t3 = str1[i - 1] == str2[j - 1] ? a[i - 1][j - 1] : a[i - 1][j - 1] + 1;
			if (t3<min) min = t3;

			a[i][j] = min;
		}
	}

	return 1.0 - (double)a[len1][len2] / max;
}


void ToLowerString(string &str)
{
	transform(str.begin(), str.end(), str.begin(), (int(*)(int))tolower);
}

int main()
{
	string mention = "";

	//return 0;
	// Coding The World!
	int T = 8;
	cin >> T;

	char xx = getchar();
	char zz = getchar();
	
	if (zz == 'E')
		while (true);
	double score_chinese;
	double score_spanish;
	double score_english;
	int count_chinese = 400;
	int count_spanish = 232;
	int count_english = 377;

	string chinese_stopword[] = {
		"b","bo","bai","bei","bao","ban","ben","banɡ","benɡ","bi","bie","biao","bian","bin","bin","bu","pa","po","pai","pei","pao","pou","pan","pen","pan","pen","pi","pie","piao","pian","pin","pinɡ","pu","ma","mo","mai","mei","mao","mou","man","men","manɡ","menɡ","mi","mie","miao","miu","mian","min","minɡ","mu","fa","fo","me","fei","fou","fan","fen","fanɡ","fenɡ","fu","da","de","dai","dei","dao","dou","dan","den","danɡ","denɡ","donɡ","di","dia","die","diao","diu","dian","dinɡ","du","duo","dui","duan","dun","ta","te","tai","tei","tao","tou","tan","tanɡ","tenɡ","tonɡ","ti","tie","tiao","tian","tinɡ","tu","tuo","tui","tuan","tun","na","ne","nai","nei","nao","nou","nan","nen","nanɡ","nenɡ","nonɡ","ni","nie","niao","niu","nian","nin","nianɡ","ninɡ","nu","nuo","nuan","nü","nüe","la","le","lai","lei","lao","lou","lan","lanɡ","lenɡ","lonɡ","li","lia","lie","liao","liu","lian","lin","lianɡ","linɡ","lu","luo","luan","lun","lü","lüe","ɡa","ɡe","ɡai","ɡei","ɡao","ɡou","ɡan","ɡen","ɡanɡ","ɡenɡ","ɡonɡ","ɡu","ɡua","guo","ɡuai","ɡui","ɡuan","ɡun","ɡuanɡ","ka","ke","kai","kao","kou","kan","ken","kanɡ","kenɡ","konɡ","ku","kua","kuo","kuai","kui","kuan","kun","kuanɡ","ha","he","hai","hei","hao","hou","han","hen","hanɡ","henɡ","honɡ","hu","hua","huo","huai","hui","huan","hun","huanɡ","ji","jia","jie","jiao","jiu","jian","jin","jianɡ","jinɡ","jiong","ju","jue","juan","junqi","qia","qie","qiao","qiu","qian","qin","qianɡ","qinɡ","qiong","qu","que","quan","qunxi","xia","xie","xiao","xiu","xian","xin","xianɡ","xinɡ","xiong","xu","xue","xuan","xunzha","zhe","zhi","zhai","zhei","zhao","zhou","zhan","zhen","zhanɡ","zhenɡ","zhonɡ","zhu","zhua","zhuo","zhuai","zhui","zhuan","zhun","zhuanɡ","cha","che","chi","chai","chao","chou","chan","chen","chanɡ","chenɡ","chonɡ","chu","chuo","chuai","chui","chuan","chun","chuanɡ","sha","she","shi","shai","shei","shao","shou","shan","shen","shanɡ","shenɡ","shu","shua","shuo","shuai","shui","shuan","shun","shuanɡ","re","ri","rao","rou","ran","ren","ranɡ","renɡ","ronɡ","ru","ruo","rui","ruan","run","za","ze","zi","zai","zei","zao","zou","zan","zen","zanɡ","zenɡ","zonɡ","zu","zuo","zui","zuan","zun","ca","ce","ci","cai","cao","cou","can","cen","canɡ","cenɡ","conɡ","cu","cuo","cui","cuan","cun","sa","se","si","sai","sao","sou","san","sen","sanɡ","senɡ","sonɡ","su","suo","sui","suan","sun","a","o","e","er","ai","ei","ao","ou","an","en","anɡ","enɡ","yi","ya","ye","yao","you","yan","yin","yanɡ","yinɡ","yonɡ","wu","wa","wo","wai","wei","wan","wen","wanɡ","wenɡ","yu","yue"

	};

	string spanish_stopword[] = {
		"un","una","unas","unos","uno","sobre","todo","también","tras","otro","algún","alguno","alguna","algunos","algunas","ser","es","soy","eres","somos","sois","estoy","esta","estamos","estais","estan","como","en","para","atras","porque","por","qué","estado","estaba","ante","antes","siendo","ambos","pero","por","poder","puede","puedo","podemos","podeis","pueden","fui","fue","fuimos","fueron","hacer","hago","hace","hacemos","haceis","hacen","cada","fin","incluso","primero","desde","conseguir","consigo","consigue","consigues","conseguimos","consiguen","ir","voy","va","vamos","vais","van","vaya","gueno","ha","tener","tengo","tiene","tenemos","teneis","tienen","el","la","lo","las","los","su","aqui","mio","tuyo","ellos","ellas","nos","nosotros","vosotros","vosotras","si","dentro","solo","solamente","saber","sabes","sabe","sabemos","sabeis","saben","ultimo","largo","bastante","haces","muchos","aquellos","aquellas","sus","entonces","tiempo","verdad","verdadero","verdadera","cierto","ciertos","cierta","ciertas","intentar","intento","intenta","intentas","intentamos","intentais","intentan","dos","bajo","arriba","encima","usar","uso","usas","usa","usamos","usais","usan","emplear","empleo","empleas","emplean","ampleamos","empleais","valor","muy","era","eras","eramos","eran","modo","bien","cual","cuando","donde","mientras","quien","con","entre","sin","trabajo","trabajar","trabajas","trabaja","trabajamos","trabajais","trabajan","podria","podrias","podriamos","podrian","podriais","yo","aquel",
		"casinadie","donnadie",
		"el","idioma","espa?ol","o","castellano","es","una","lengua","romance","procedente","del","latín","vulgar","pertenece","al","grupo","ibérico","y","es","originaria","de","Castilla","una","región","histórica","de","la","península","ibérica","en","la","actual","espa?a","Se","conoce","también","por","el","americanismo","coloquial","castilla","nota","común","en","áreas","rurales","e","indígenas","entre","México","y","la","patagonia"
	};

	string english_stopword[] = {
		"english", "a", "about", "above", "above", "across", "after", "afterwards", "again", "against", "all", "almost", "alone", "along", "already", "also","although","always","am","among", "amongst", "amoungst", "amount",  "an", "and", "another", "any","anyhow","anyone","anything","anyway", "anywhere", "are", "around", "as",  "at", "back","be","became", "because","become","becomes", "becoming", "been", "before", "beforehand", "behind", "being", "below", "beside", "besides", "between", "beyond", "bill", "both", "bottom","but", "by", "call", "can", "cannot", "cant", "co", "con", "could", "couldnt", "cry", "de", "describe", "detail", "do", "done", "down", "due", "during", "each", "eg", "eight", "either", "eleven","else", "elsewhere", "empty", "enough", "etc", "even", "ever", "every", "everyone", "everything", "everywhere", "except", "few", "fifteen", "fify", "fill", "find", "fire", "first", "five", "for", "former", "formerly", "forty", "found", "four", "from", "front", "full", "further", "get", "give", "go", "had", "has", "hasnt", "have", "he", "hence", "her", "here", "hereafter", "hereby", "herein", "hereupon", "hers", "herself", "him", "himself", "his", "how", "however", "hundred", "ie", "if", "in", "inc", "indeed", "interest", "into", "is", "it", "its", "itself", "keep", "last", "latter", "latterly", "least", "less", "ltd", "made", "many", "may", "me", "meanwhile", "might", "mill", "mine", "more", "moreover", "most", "mostly", "move", "much", "must", "my", "myself", "name", "namely", "neither", "never", "nevertheless", "next", "nine", "no", "nobody", "none", "noone", "nor", "not", "nothing", "now", "nowhere", "of", "off", "often", "on", "once", "one", "only", "onto", "or", "other", "others", "otherwise", "our", "ours", "ourselves", "out", "over", "own","part", "per", "perhaps", "please", "put", "rather", "re", "same", "see", "seem", "seemed", "seeming", "seems", "serious", "several", "she", "should", "show", "side", "since", "sincere", "six", "sixty", "so", "some", "somehow", "someone", "something", "sometime", "sometimes", "somewhere", "still", "such", "system", "take", "ten", "than", "that", "the", "their", "them", "themselves", "then", "thence", "there", "thereafter", "thereby", "therefore", "therein", "thereupon", "these", "they", "thickv", "thin", "third", "this", "those", "though", "three", "through", "throughout", "thru", "thus", "to", "together", "too", "top", "toward", "towards", "twelve", "twenty", "two", "un", "under", "until", "up", "upon", "us", "very", "via", "was", "we", "well", "were", "what", "whatever", "when", "whence", "whenever", "where", "whereafter", "whereas", "whereby", "wherein", "whereupon", "wherever", "whether", "which", "while", "whither", "who", "whoever", "whole", "whom", "whose", "why", "will", "with", "within", "without", "would", "yet", "you", "your", "yours", "yourself", "yourselves", "the",

		"english","uses","strange","spelling","when","written","different","words","can","use","the","same","letters","and","combinations","for","very","different","sounds","many","english","speaking","countries","spell","words","differently","there","is","a","difference","between","some","spellings","in","america","on","the","one","hand","and","on","the","other","hand","the","United","Kingdom","and","many","other","countries","where","English","is","the","main","language"
	};

	while (T--)
	{
		score_chinese = 0.0;
		score_spanish = 0.0;
		score_english = 0.0;
		
		
		int count = 0;
		while (cin >> mention)
		{
			if (count == 30)
				break;
			count++;
			//cout << mention << endl;
			ToLowerString(mention);
			int len_mention = mention.size();
			double t_score;
			t_score = -9999;
			for (int i = 0; i<count_chinese; i++)
			{
				int len_chinese_stopword = chinese_stopword[i].size();
				t_score = max(t_score, stringSimilarity(mention, chinese_stopword[i], len_mention, len_chinese_stopword));
			}
			
			score_chinese += t_score;

			t_score = -9999;
			for (int i = 0; i<count_spanish; i++)
			{
				int len_spanish_stopword = spanish_stopword[i].size();
				t_score = max(t_score, stringSimilarity(mention, spanish_stopword[i], len_mention, len_spanish_stopword));
			}
			score_spanish += t_score;

			t_score = -9999;
			for (int i = 0; i<count_english; i++)
			{
				
				int len_english_stopword = english_stopword[i].size();
				t_score = max(t_score, stringSimilarity(mention, english_stopword[i], len_mention, len_english_stopword));
			}
			score_english += t_score;
		}

		//cout << score_chinese/count<< " " << score_spanish/count << " " << score_english/count<< endl;

		double score = score_chinese;
		string ans = "Chinese Pinyin";

		if (score_spanish > score)
		{
			score = score_spanish;
			ans = "Spanish";
		}
		if (score_english > score)
		{
			score = score_english;
			ans = "English";
		}
		cout << ans << endl;
		getline(cin, mention);
	}
	return 0;
}