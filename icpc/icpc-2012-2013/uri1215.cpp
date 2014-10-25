#include <cstdio>
#include <set>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

int main() {
	
	char input[5000];
	set<string> s;
	int j;
	char buffer[5000];
	
	while (scanf("%s", input) == 1 )
	{
		int tam = strlen(input);
		
		j = 0;
		for (int i = 0; i < tam; ++i) {
			if ( isalpha(input[i]) )
				buffer[j++] = tolower(input[i]);
			else {
				buffer[j] = '\0';
				if (j > 0)
					s.insert(buffer);
				j = 0;
			}
		}
		buffer[j] = '\0';
		if (j > 0)
			s.insert(buffer);
		
	}
	
	for (set<string> ::iterator it = s.begin(); it != s.end(); ++it)
		puts(it->c_str());
	
	return 0;
}