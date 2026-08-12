import java.util.Scanner;


public class Q18 {

    
    static int bitsToInt(String bits) {
        int result = 0;
        for (char bit : bits.toCharArray()) {
            result = (result << 1) | (bit - '0'); 
        }
        return result;
    }

    
    static char valueOf(int decimal) {
        if (decimal <= 25) {
            return (char) ('A' + decimal);
        } else if (decimal <= 51) {
            return (char) ('a' + (decimal - 26));
        } else if (decimal <= 61) {
            return (char) ('0' + (decimal - 52));
        } else if (decimal == 62) {
            return '+';
        } else {
            return '/';
        }
    }

    
    static String encode(String bits) {
        if (bits == null || bits.isEmpty()) {
            return "";
        }

        StringBuilder result = new StringBuilder();
        int length = bits.length();


        for (int i = 0; i < length / 6; i++) {
            int decimal = bitsToInt(bits.substring(i * 6, (i + 1) * 6));
            result.append(valueOf(decimal));
        }


        if (length % 6 != 0) {
            StringBuilder paddedBits = new StringBuilder(bits);
            for (int i = 0; i < 6 - (length % 6); i++) {
                paddedBits.append('0');
            }
            
            int start = length - (length % 6);
            int decimal = bitsToInt(paddedBits.substring(start, start + 6));
            result.append(valueOf(decimal));
        }


        int byteRemainder = (length / 8) % 3;
        if (byteRemainder != 0) {
            for (int i = 0; i < 3 - byteRemainder; i++) {
                result.append('=');
            }
        }

        return result.toString();
    }


    static String charToBits(char c) {
        StringBuilder sb = new StringBuilder(8);

        for (int i = 7; i >= 0; i--) {
            sb.append(((c >> i) & 1) == 1 ? '1' : '0');
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Input: ");
        String input = sc.nextLine();

        StringBuilder allBits = new StringBuilder();
        for (char c : input.toCharArray()) {
            allBits.append(charToBits(c));
        }

        String output = encode(allBits.toString());
        System.out.println("Base64 Output: " + output);
        sc.close();
    
    }
}