#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
  typedef unsigned long long hash_type;
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    int n = s.size();
    int m = words.size();
    if (n==0 || m==0) return ret;

    int c = words[0].size();
    if (c == 0 || n < c) return ret;

    const int prm = 127;

    //use multiset to torlerate duplicate words or use set to ignore duplicate words
    multiset<hash_type> sw, sw1;
    for (int i=0; i<m; ++i) {
      if (words[i].size() != c) return ret;
      hash_type h = hash(words[i], 0, c-1, prm);
      sw.insert(h);
    }
    if (sw.size() < m) m = sw.size();//to ignore duplicate word if sw/sw1 are set

    vector<hash_type> hs;
    roll_hash(s, hs, c, prm);

    int i = 0, j;
    multiset<hash_type>::iterator it;
    while (i<=n-c*m) {

      sw.insert(sw1.begin(), sw1.end());
      sw1.clear();

      for (j=i; j<i+c*m; j+=c) {
	it = sw.find(hs[j]);
	if (it == sw.end()) {
	  break;
	}
	sw1.insert(*it);
	sw.erase(it);
      }
      if (j==i+c*m) {
	ret.push_back(i);
      }
      ++i;
    }
    return ret;
  }

  hash_type hash(const string &s, int i, int j, int prm) {
    hash_type t = 0;
    for(int k=i; k<=j; ++k) {
      t = t * prm + s[k];
    }
    #ifdef DEBUG_HASH
    cout << s << ' ' << t << '\n';
    #endif
    return t;
  }

  void roll_hash(const string &s, vector<hash_type> &v, int c, int prm) {
    int n = s.size();
    v.reserve(n-c+1);
    hash_type h = hash(s, 0, c-1, prm);
    v[0] = h;
    int i=1, j=c;
    hash_type off = power(prm, c);cout << off << '\n';
    while (i <= n-c) {
      h = h * prm - off * s[i-1] + s[j];
      v[i] = h;
      #ifdef DEBUG_HASH
      cout << s.substr(i, j-i+1) << ' ' << v[i] << '\n';
      #endif
      ++i, ++j;
    }
  }

  //pow returns 0
  hash_type power(hash_type base, hash_type exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    if (exp == 2) return base * base;

    /**
     base_power[0] = pow(base, pow(2,0)) = pow(base, 1)
     base_power[1] = pow(base, pow(2,1)) = pow(base, 2)
     base_power[2] = pow(base, pow(2,2)) = pow(base, 4)
     **/
    vector<hash_type> base_power;
    base_power.push_back(base);//m[0] saves base to the 1(pow(2,0) = 1)
    hash_type i=0;
    while (exp >= (1<<(i+1))) {
      ++i;
      base_power.push_back(base_power[i-1] * base_power[i-1]);
    }

    hash_type ret = 1;
    while (exp) {
      if (exp >= (1<<i)) {
	ret *= base_power[i];
	exp -= (1 << i);
      }
      --i;
    }
    return ret;
  }
};


#ifdef DEBUG

int main() {
  Solution s;
  char* a[] = {"pbolvrtdfefhqxcrrofyc","mewjykbnzjeazrxrkayoh","fgekzwyewctbyczidokos","kojihvkflslryxruvxrzq","uytvgyjsndddmnkhzrstc","lsbeowchwsbwnwemhxbkc","gwpqfqjzmmlenpumrckmd","gzcmnjjqulwscoytyxhkk","lzahntjzfphhruwadnwpj","ptypmwovizijzqzuzycog","jhahkdugugxoemccbymag","vbyuxytzobkwbsigoobuo","raatedrqfamiyigydhpes","lhmvoajrxzixabcfvslxg","vvpbwujlzdygptureloet","ogxslsmyrtuokxkeivflv","mcoiutwkzryfoqsidtzyp","qkmaqxywktknisjdoteis","jykdhpyipnyzcbqzzolsy","ycsjfjdjrxupjayzyhqoh","qqiirjyccwdgoomxtxqqu","gcwedwntkxlcfvvrtatpf","bgtnfnnwfjchfikdwgotr","sanorgqmyvoeqdldshldl","siufoslencwprmhyevwzl","cqrpvlzgpkbzggnytrnxq"};
  vector<string> v;
  for (int i=0; i<sizeof(a)/sizeof(char*); ++i)
    v.push_back(a[i]);
  string ss("dlmogiklbqfggokuonfgugiyammwvwhbjvrqgdbjtipcwzwmobtjjdhmpvknrsqbpjtvmwfifukbwgokjjvvmeheatttljwdupygofotcywygmksvipkmyqmrjifueiouiukoldqlzquocojkdvzdlnuuvbqajewubgiolazmsvaujmfohervtorppipbolvrtdfefhqxcrrofycmewjykbnzjeazrxrkayohfgekzwyewctbyczidokoskojihvkflslryxruvxrzquytvgyjsndddmnkhzrstclsbeowchwsbwnwemhxbkcgwpqfqjzmmlenpumrckmdgzcmnjjqulwscoytyxhkklzahntjzfphhruwadnwpjptypmwovizijzqzuzycogjhahkdugugxoemccbymagvbyuxytzobkwbsigoobuoraatedrqfamiyigydhpeslhmvoajrxzixabcfvslxgvvpbwujlzdygptureloetogxslsmyrtuokxkeivflvmcoiutwkzryfoqsidtzypqkmaqxywktknisjdoteisjykdhpyipnyzcbqzzolsyycsjfjdjrxupjayzyhqohqqiirjyccwdgoomxtxqqugcwedwntkxlcfvvrtatpfbgtnfnnwfjchfikdwgotrsanorgqmyvoeqdldshldlsiufoslencwprmhyevwzlcqrpvlzgpkbzggnytrnxqdpekpjhnivraogwzfeoqfoynbzgvmelpvpbkyjxjgojuwhtcmkurysfbrnwerjvozxazixionukkbfonpihpcorwbpcvzxjaukzejksxeejhkxxzhgpjuihvxjqyhaydmaivkcuqhdztcyulelvyteutokrxmscasmwepswyyxrawnmazjbsnvndhfcwzfwrruxinvilsbnopbroksiapwfydkwcptvipstepbphffyugrktlsvaqaatkxxbssmhmhmbidjpijjravklofnghnaumxvesjoeqcibhtqsccjextpnaeuhtwdgvbknkaubccemvuezyndwiujkyftrbxxzykmkkilpkrdhohgmwjigduqdbjvdgueggqrtbeknwnvkubysnjysdowgztjipnowghpjmbwkorwkvuckfaciqaprvazlqqjyxahlbdxpxvzusdexfiivlzogbotrgerfeathgqydmxzgcddhnleykthmjcfphzwnzpvfgtkutjavoffcrjcdejrpoxevydkxsffabruwbwtrcytvkyyqhqgvpmsnpdmiktinlflmdffffzcrxbigtqeicyxudlcofmdqtpexwjebkhtjidsdtwlvwkpavtqaitsbkyagifiumdewgwzzumwqyoqtjgwrcqvmpvtzadtogxmmvnlrzjixxathjpylhvzwruvtxpkdowrmkedlonjloeuxtvkcqjzjeuddlnhalamvfrhvfsitwdsryetqnu");
  vector<int> r = s.findSubstring(ss, v);
  int n = v.size() * v[0].size();
  for (int i=0; i<r.size(); ++i) {
    cout << ss.substr(r[i], n) << '\n';
  }
  
}

#endif
