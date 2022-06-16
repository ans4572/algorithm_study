import java.util.*;
import java.io.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Info implements Comparable<Info> {
	int a;
	int b;
	int cost;

	Info(int a, int b, int cost) {
		this.a = a;
		this.b = b;
		this.cost = cost;
	}

	@Override
	public int compareTo(Info i) {
		return i.cost < cost ? 1 : -1;
	}
}

public class Main {

	static int[] parent;
	static int n, m, sum = 0;
	static ArrayList<Info> list;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());

		list = new ArrayList<>();
		parent = new int[n + 1];

		for (int i = 0; i < m; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());

			list.add(new Info(a, b, cost));

		}

		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		Collections.sort(list);

		for (Info i : list) {
			if (!isCycle(i.a, i.b))
				sum += i.cost;
		}
		
		System.out.println(sum);

		br.close();
	}

	public static int findParent(int a) { // 부모찾기
		if (parent[a] == a)
			return a;
		else
			return findParent(parent[a]);
	}

	public static boolean isCycle(int a, int b) {
		a = findParent(a);
		b = findParent(b);

		if (a == b)
			return true; // 사이클 형성됨
		else {
			parent[a] = b;
			return false;
		}
	}

}
