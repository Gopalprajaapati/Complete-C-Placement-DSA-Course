import java.util.*;

public class DigitPatternSolver {

    static Map<String, Character> patterns = new HashMap<>();
    static List<String> digits = Arrays.asList(
            " _ | _|", "     |  |", " _  __ ", " _  _| _|",
            "   |_|  |", " _ |_  _|", " _ |_ |_|", " _   |  |",
            " _ |_||_|", " _ |_| _|"
    );

    static {
        patterns.put(" _ | _|", '0');
        patterns.put("     |  |", '1');
        patterns.put(" _  __ ", '2');
        patterns.put(" _  _| _|", '3');
        patterns.put("   |_|  |", '4');
        patterns.put(" _ |_  _|", '5');
        patterns.put(" _ |_ |_|", '6');
        patterns.put(" _   |  |", '7');
        patterns.put(" _ |_||_|", '8');
        patterns.put(" _ |_| _|", '9');
        patterns.put("         ", '=');
        patterns.put("    _  _ ", '+');
        patterns.put("         ", '-');
        patterns.put(" _ |_   |", '*');
        patterns.put(" _ |_|  |", '%');
    }

    static int evaluate(List<Character> expression) {
        int lhs = 0, num = 0;
        char op = '+';

        for (char c : expression) {
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else {
                switch (op) {
                    case '+': lhs += num; break;
                    case '-': lhs -= num; break;
                    case '*': lhs *= num; break;
                    case '%': lhs %= num; break;
                }
                num = 0;
                op = c;
            }
        }
        lhs += num;
        return lhs;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] display = new String[3];

        for (int i = 0; i < 3; i++) {
            display[i] = scanner.nextLine();
        }

        List<String> characters = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringBuilder ch = new StringBuilder();
            for (int j = 0; j < 3; j++) {
                ch.append(display[j], i * 3, (i + 1) * 3);
            }
            characters.add(ch.toString());
        }

        List<Character> equation = new ArrayList<>();
        for (String ch : characters) {
            equation.add(patterns.get(ch));
        }

        int rhs = equation.remove(equation.size() - 1) - '0'; // Right-hand side value
        equation.remove(equation.size() - 1); // Remove the '=' symbol
        int result = evaluate(equation);

        for (int i = 0; i < n; i++) {
            String original = characters.get(i);
            for (String d : digits) {
                if (d.equals(original)) continue;

                characters.set(i, d);
                List<Character> temp = new ArrayList<>();
                for (String ch : characters) {
                    temp.add(patterns.get(ch));
                }

                if (evaluate(temp) == rhs) {
                    System.out.println(i + 1);
                    scanner.close();
                    return;
                }
            }
            characters.set(i, original);
        }
        scanner.close();
    }
}
