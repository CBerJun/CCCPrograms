import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class J5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        int n = sc.nextInt();
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }
        for (int i = 0; i < n; i++) {
            b.add(sc.nextInt());
        }
        Collections.sort(a);
        if (q == 1) {
            Collections.sort(b);
        }
        else {
            Collections.sort(b, Collections.reverseOrder());
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Math.max(a.get(i), b.get(i));
        }
        System.out.println(sum);
        sc.close();
    }
}
