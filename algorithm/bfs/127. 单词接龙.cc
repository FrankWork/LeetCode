#include "../template.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& vocab) {
        /* beginWord = "hit",  endWord = "cog",
           vocab = ["hot","dot","dog","lot","log","cog"]
           "hit" -> "hot" -> "dot" -> "dog" -> "cog",

           对单词建图，若单词之间只有一个字符不同，则两单词有边相连，
           使用BFS找到最短路径
        */
       vocab.push_back(beginWord);
       int endIdx=-1;
       for(int i=0;i<vocab.size() && endIdx==-1;++i){
          if(vocab[i]==endWord)
              endIdx = i;
       }
       if(endIdx==-1) return 0;
      
       // build graph
       int n=vocab.size();
       vector<vector<int>> graph(n);
       for(int i=0;i<n;++i){
         for(int j=0;j<i;++j){
           if(isConnect(vocab[i], vocab[j])){
             graph[i].push_back(j);
             graph[j].push_back(i);
           }
         }
       }

      //  print2d(graph);
      // for(int i=0;i<n;++i)
      //   printf("%d ", (int)graph[i].size());
      //   cout<<endl;
      //  return 0;

       // bfs
       queue<int> q;
       q.push(n-1);
       vector<bool> used(n);
       used[n-1]=true;
       int path=1;       
       while(!q.empty()){
          int nq = q.size();
          path++;
          // printf("%d %d %d\n", n, nq, path);
          while(nq-- > 0){
             int cur=q.front();
             q.pop();
             for(int i=0;i<graph[cur].size();++i){
                  int next= graph[cur][i];
                  if(next==endIdx) return path;

                  if(used[next]) continue;

                  used[next] = true;
                  
                  q.push(next);
                  
             }
          }
       }

       return 0;
    }

    bool isConnect(const string& a, const string &b){
      int cnt=0;
      int i=0, j=0;
      for(int i=0;i<a.length() &&cnt<=1; ++i){
        if(a[i]!=b[i]) cnt++;
      }

      return cnt==1;
    }
};


int main(){
       Solution so;
      //  vector<string> vocab{"hot","dot","dog","lot","log","cog"};
      //  cout << so.ladderLength("hit", "cog", vocab)<<endl;

       vector<string> vocab{
         "kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"
       };
       cout << so.ladderLength("cet", "ism", vocab)<<endl;
} 