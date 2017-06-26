/* 126. Word Ladder II */
#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

bool ladder(string s1,string s2){
  int count = 0;
  for(int i = 0; i != s1.size();i++){
    if(s1[i] != s2[i])
      count++;
  }
  return count==1;
}
bool findLadders_1(string begin, string end,
                   vector<string>& wList,
                   vector<vector<string> >& path,
                   vector<string>& cand,
                   unordered_map<string,int>& mmap){
  if(begin.compare(end) == 0){
    if(path.empty())
      path.push_back(cand);
    else{
      int size = (path.back()).size();
      if(size == cand.size())
        path.push_back(cand);
      else if(size > cand.size()){
        path.clear();
        for(int i = 0; i != path.size();i++)
          for(int j = 0; j != path[i].size();j++)
            mmap[path[i][j]]--;
        for(int i =0; i != cand.size(); i++)
          mmap[cand[i]] = i+1;
        path.push_back(cand);
      }
      else
        ;
    }
    return true;
  }
  bool flag = false;
  for(auto s:wList){
    if(mmap[s] != 0
       && mmap[s] <= cand.size())
      continue;
    if(ladder(begin,s)){
      mmap[s] = cand.size()+1;
      cand.push_back(s);
      bool flag1 = findLadders_1(s,end,wList,path,cand,mmap);
      if(!flag1)
        mmap[s]--;
      if(flag1)
        flag = true;
      cand.pop_back();
    }
  }
  return flag;
}
vector<vector<string> > findLadders(string beginWord, string endWord,
                                    vector<string>& wordList){
  vector<vector<string> > path;
  unordered_map<string,int> mmap;
  vector<string> cand;
  cand.push_back(beginWord);
  mmap[beginWord]++;
  findLadders_1(beginWord,endWord,wordList,path,cand,mmap);
  return path;
}

int main()
{
  string begin("cet");
  string end("ism");
  string b[]={"hot","dot","dog","lot","log","cog"};
  string a[]={"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
  string c[]={"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
  string bd("red"),ed("tax");
  string d[]={"ted","tex","red","tax","tad","den","rex","pee"};
  vector<string> wld(d,d+8);
  vector<string> wl(a,a+95);
  vector<string> wlb(b,b+6);
  vector<string> wlc(c,c+599);
  vector<vector<string> > res = findLadders(bd,ed,wld);
  for(int i = 0; i != res.size();i++){
    cout<<"[";
    for(int j = 0; j != res[i].size();j++)
      cout<<res[i][j]<<",";
    cout<<"]"<<endl;
  }
  return 1;
}
