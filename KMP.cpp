int KMP(string text, string pat) {

	int m = text.length(), n = pat.length();

	vector<int> lps(n);
	lps[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = lps[i - 1];
		while (j > 0 && pat[j] != pat[i])
			j = lps[j - 1];
		if (pat[i] == pat[j])
			j++;
		lps[i] = j;
	}

	int i = 0, j = 0;
	while (i < m) {
		if (text[i] == pat[j])
			i++, j++;
		if (j == n)
			return i - j;
		else if (i < m && text[i] != pat[j]) {
			if (j > 0)
				j = lps[j - 1];
			else
				i++;
		}
	}

	return -1;
}