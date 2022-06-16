import java.util.*;
import java.io.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {

	static int[] in, post, pre;
	static int n;
	static int pos; // pre 순서대로 저장될 값
	
	
	// 인오더 : 8 4 9 2 5 1 6 3 7
	// 포스트 : 8 9 4 5 2 6 7 3 1 
	

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		n = Integer.parseInt(br.readLine());
		
		in = new int[n];
		post = new int[n];
		pre = new int[n];

		String[] str = br.readLine().split(" ");
		for (int i = 0; i < n; i++)
			in[i] = Integer.parseInt(str[i]);

		str = br.readLine().split(" ");
		for (int i = 0; i < n; i++)
			post[i] = Integer.parseInt(str[i]);

		getPreorder(0, n - 1, 0, n - 1);

		for (int n : pre)
			bw.write(n + " ");

		bw.flush();
		br.close();
	}

	public static void getPreorder(int is, int ie, int ps, int pe) { // is / ie :인오더 start, end && ps / pe : 포스트오더 start , end
		if (is <= ie && ps <= pe) {
			pre[pos++] = post[pe];	// 포스트의 맨 마지막값은 프리에 순차적으로 저장됨.

			int idx = is;
			for (int i = is; i <= ie; i++) {
				if (in[i] == post[pe]) {
					idx = i;
					break;
				}
			}

			getPreorder(is, idx - 1, ps, ps + idx - is - 1);
			getPreorder(idx + 1, ie, ps + idx - is, pe - 1);

		}
	}
}
