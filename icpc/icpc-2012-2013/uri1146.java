import java.util.*;

class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	while (sc.hasNext()) {
	    int n = sc.nextInt();
	    if (n == 0)
		break;

	    int i;
	    for (i = 1; i < n; ++i) {
		System.out.print(i + " ");
	    }
	    System.out.println(i);
	}
    }
}

/*
5
3
10
0
*/
