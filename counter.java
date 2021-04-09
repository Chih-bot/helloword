
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Stack;
import java.util.regex.Pattern;

public class counter extends JFrame implements ActionListener {

    public counter() {

        super("计算器");
        setLayout(null);
        setBounds(300, 400, 300, 450);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);
        result.setBounds(20, 5, 250, 30);
        result.setEditable(false);
        add(result);
        int x = 20, y = 55;
        for (int i = 0; i < keys.length; i++)//放置按钮
        {
            key[i] = new JButton();
            key[i].setText(keys[i]);
            key[i].setBounds(x, y, 60, 40);
            if (x < 215) {
                x += 65;
            } else {
                x = 20;
                y += 45;
            }
            key[i].addActionListener(this);
            this.add(key[i]);
        }
        setVisible(true);
    }

    private JTextField result = new JTextField();
    private String[] keys = {"7", "8", "9", "*", "4", "5", "6", "-", "1", "2", "3", "+", "0", "/", "c", ".", "=", "(", ")", "AC"};
    private JButton key[] = new JButton[keys.length];
    private Stack<Character> optr = new Stack<Character>();
    private Stack<Double> opnd = new Stack<Double>();
    private Stack<String> kuohao=new Stack<String>();
    private boolean pointlock=true;
    @Override
    public void actionPerformed(ActionEvent e) {

        String label = e.getActionCommand();
        String value = result.getText();
        String last_value;
        if (value.length() == 0)
            last_value = "";
        else
            last_value = value.substring(value.length() - 1, value.length());
        if (Pattern.matches("\\d", label)) {
            if (Pattern.matches("[)]", last_value)) {
            }
            result.setText(value + label);
        } else if (Pattern.matches("[-*/+]", label)) {
            if (Pattern.matches("[\\d()]", last_value)) {
                result.setText(value + label);
                pointlock=true;
            }
        }
        else if(label=="("&&!Pattern.matches("[()]",last_value)){
            result.setText(value+label);
            kuohao.push(label);
        }
        else if(label=="."&&Pattern.matches("\\d",last_value)&&pointlock){

                result.setText(value+label);
                pointlock=false;
        }
        else if (label==")"&&!Pattern.matches("[()]",last_value)&&!kuohao.empty()){

            result.setText(value+label);
            kuohao.pop();
        }
        else if (label == "AC")
            result.setText("");
        else if (label == "c") {
            if (result.getText().length() != 0) {
                String s = value.substring(0, result.getText().length() - 1);
                result.setText(s);

            }
        } else if (label == "=") {
            if(kuohao.empty()){
            result.setText(value + label);
            count(result.getText());
            }
            else
                JOptionPane.showMessageDialog(null,"计算式有错","错误",JOptionPane.WARNING_MESSAGE);

        }
    }

    private void count(String value) {
        optr.clear();
        opnd.clear();
        optr.push('=');
        char c[] = value.toCharArray();
        int i = 0;
        String x = "";
        while (!optr.empty()) {
            String p = String.valueOf(c[i]);


            if (Pattern.matches("[0-9.]", p)) {
                String n = String.valueOf(c[i + 1]);
                x = x + p;
                if (Pattern.matches("[()/*+=-]", n)) {
                    Double k = Double.valueOf(x);
                    opnd.push(k);
                    x = "";

                }
                i++;
            }
            else {
                char item = optr.peek();
                switch (precede(item, c[i])) {
                    case -1:
                        optr.push(c[i]);
                        i++;
                        break;
                    case 0:
                        item = optr.pop();
                        if (item!= '=')
                            i++;
                        break;
                    case 1:
                        char theta = optr.pop();
                        Double b = opnd.pop();
                        Double a = opnd.pop();

                        opnd.push(opearate(a, theta, b));


                }

            }


        }

        Double num = opnd.pop();
        result.setText(String.valueOf(num));
    }





    private int inStack(char i){
        int in=0;
        switch (i){
            case '=': in=0;break;
            case '(':in=1;break;
            case '*':in=5;break;
            case '/':in=5;break;
            case '+':in=3;break;
            case ')':in=6;break;
            case '-':in=3;break;
        }
        return in;
    }
    private int outStack(char i){
        int out=0;
        switch (i){
            case '=': out=0;break;
            case '(':out=6;break;
            case '*':out=4;break;
            case '/':out=4;break;
            case '+':out=2;break;
            case ')':out=1;break;
            case '-':out=2;break;
        }
        return out;
    }
    private int precede(char i,char b){
        if(inStack(i)<outStack(b)) return -1;
        else if(inStack(i)==outStack(b)) return 0;
        else return 1;
    }
    private double opearate(double a,char p,double b){
        double re=0;
        switch (p) {
            case '+':
                re = a + b;
                break;
            case '-':
                re = a - b;
                break;
            case '*':
                re = a * b;
                break;
            case '/':
                re = a / b;

                break;
        }
        return re;
    }

}








