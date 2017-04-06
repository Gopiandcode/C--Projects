import java.math.*;
import java.util.*;
import java.io.*;

class Main {
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextBigInteger()) {

            // Set up the variables
            BigInteger value;
            BigInteger minimal = null;
            BigInteger maximal = null;
            BigInteger max_seen = null;

            // Keep on checking values till the end condition is reached.
            while(!(value = sc.nextBigInteger()).equals(BigInteger.valueOf(-999999))){
                BigInteger min;
                BigInteger max;

                // Just checks to initialize the variables on the first run.
                if(minimal == null) minimal = BigInteger.ONE;
                if(maximal == null) maximal = BigInteger.ONE;
                if(max_seen == null) max_seen = value;

                // The maximum possible value can be retrieved each time
                // by either multiplying the minimal value by a negative one
                // or multiplying the maximal value by a positive one.
                if(value.compareTo(BigInteger.ZERO) == -1) {
                    min = maximal.multiply(value);
                    max = minimal.multiply(value);
                } else {
                    min = minimal.multiply(value);
                    max = maximal.multiply(value);
                }

                // If the values are large update the largest seen value.
                // Both min and max are checked to deal with edge cases with
                // only negative values.
                if(min.compareTo(max_seen) == 1) max_seen = min;
                if(max.compareTo(max_seen) == 1) max_seen = max;
                if(value.compareTo(max_seen) == 1) max_seen = value;

                // Finally check if the new min and max values are large or small
                // enough to continue the minimal maximal chain. If not reset the
                // counter.
                minimal = value.compareTo(min) == -1 ? value : min;
                maximal = value.compareTo(max) == 1 ? value : max;


            }
            // Once done, print out the result.
            System.out.println(max_seen);
        }

    }

}
