import java.util.*;
import java.io.*;

public class Egg_Drop {
    static int eggDrop(int n,int k)
    {
//        boundary condition
//        if 1 egg and k floors, min attempt = k
//        if n eggs and 1 floor, min attempt =1
        int T[][]=new int[n][k+1];
        for (int i = 0; i <=k; i++) {
            T[0][i]=i;
        }
        for (int i = 0; i < n; i++) {
            T[i][0]=0;
            T[i][1]=1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 2; j <=k; j++) {
                T[i][j]=999;
                for(int x=1;x<=j;x++)
                {
                    int res=1+Math.max(T[i-1][x-1],T[i][j-x]);
                    if(res<T[i][j])
                    {
                        T[i][j]=res;
                        
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <=k; j++) {
                System.out.print(T[i][j]+" ");
            }
            System.out.println("");
        }
        return (T[n-1][k]);
    }
    public static void main(String[] args) {
        int N=2;  //eggs
        int K=4;
        System.out.println("Minimum Attempts: "+eggDrop(N,K));
        
    }

}
