//Manacher's Algo

vector<int> manacher(string &s) {
	int n = (int)s.size();
	vector<int> p(n);
	//p[i] = longest palindrome centred at i of length 2*p[i]+1
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		if (i <= r)
			p[i] = min(r - i, p[l + (r - i)]);
		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && s[i - p[i] - 1] == s[i + p[i] + 1])
			++p[i];
		if (i + p[i] > r) {
			l = i - p[i];
			r = i + p[i];
		}
	}
}

int main() {

	//pre-process the string to make all palindromes of odd length
	string s = "#";
	for (auto c : t) {
		s += c;
		s += '#';
	}

	vector<int> p = manacher(s);

}
