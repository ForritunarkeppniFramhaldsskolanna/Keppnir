import java.util.*;
import java.math.*;
import java.io.*;

import java.util.Objects;

class Complex {
    private final double re;   // the real part
    private final double im;   // the imaginary part

    // create a new object with the given real and imaginary parts
    public Complex(double real, double imag) {
        re = real;
        im = imag;
    }

    // return a string representation of the invoking Complex object
    public String toString() {
        if (im == 0) return re + "";
        if (re == 0) return im + "i";
        if (im < 0) return re + " - " + (-im) + "i";
        return re + " + " + im + "i";
    }

    // return abs/modulus/magnitude
    public double abs() {
        return Math.sqrt(re * re + im * im);
    }

    // return a new Complex object whose value is (this + b)
    public Complex plus(Complex b) {
        Complex a = this;             // invoking object
        double real = a.re + b.re;
        double imag = a.im + b.im;
        return new Complex(real, imag);
    }

    // return a new Complex object whose value is (this - b)
    public Complex minus(Complex b) {
        Complex a = this;
        double real = a.re - b.re;
        double imag = a.im - b.im;
        return new Complex(real, imag);
    }

    // return a new Complex object whose value is (this * b)
    public Complex times(Complex b) {
        Complex a = this;
        double real = a.re * b.re - a.im * b.im;
        double imag = a.re * b.im + a.im * b.re;
        return new Complex(real, imag);
    }

    // return a new Complex object whose value is the reciprocal of this
    public Complex reciprocal() {
        double scale = re * re + im + im;
        return new Complex(re / scale, (-im) / scale);
    }

    // return the real or imaginary part
    public double re() { return re; }
    public double im() { return im; }

    // return a / b
    public Complex divides(Complex b) {
        Complex a = this;
        return a.times(b.reciprocal());
    }

    // See Section 3.3.
    public boolean equals(Object x) {
        if (x == null) return false;
        if (this.getClass() != x.getClass()) return false;
        Complex that = (Complex) x;
        return (this.re == that.re) && (this.im == that.im);
    }

    // See Section 3.3.
    public int hashCode() {
        return Objects.hash(re, im);
    }
}


public class atli_translated_100 {
    private static Scanner in;
    private static PrintWriter out;
    private static int mxsz = 262144;
    static void fft(ArrayList<Complex> x, int n, boolean inv) {
        for(int i = 0, j = 0; i < n; i++) {
            if(i < j) {
                Complex temp = x.get(i);
                x.set(i, x.get(j));
                x.set(j, temp);
            }
            int m = n >> 1;
            while(1 <= m && m <= j) {
                j -= m;
                m >>= 1;
            }
            j += m;
        }
        for(int mx = 1; mx < n; mx <<= 1) {
            double r = 1.0;
            double theta = (inv ? -1 : 1) * Math.PI / mx;
            Complex wp = new Complex(r * Math.cos(theta), r * Math.sin(theta));
            Complex w = new Complex(1, 0);
            for(int m = 0; m < mx; m++, w = w.times(wp)) {
                for(int i = m; i < n; i += mx << 1) {
                    Complex t = x.get(i + mx).times(w);
                    x.set(i + mx, x.get(i).minus(t));
                    x.set(i, x.get(i).plus(t));
                } 
            } 
        } 
        if(inv) {
            for(int i = 0; i < n; i++) {
                x.set(i, x.get(i).divides(new Complex(n, 0)));
            }
        }
    };

    static int readTo(ArrayList<Complex> a) {
        a.clear();
        int sz = in.nextInt();
        for(int i = 0; i < mxsz; ++i) {
            a.add(new Complex(0, 0));
        }
        for(int i = 0; i < sz; ++i) {
            int x = in.nextInt();
            a.set(x, a.get(x).plus(new Complex(1, 0)));
        }
        fft(a, mxsz, false);
        return sz;
    }
    
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out, false);
        
        int n = in.nextInt();
        ArrayList<Complex> p = new ArrayList<Complex>();
        ArrayList<Complex> q = new ArrayList<Complex>();
        out.flush();
        long denom = readTo(p);
        for (int i = 1; i < n; i++) {
            out.flush();
            denom *= readTo(q);
            for (int j = 0; j < mxsz; j++) {
                p.set(j, p.get(j).times(q.get(j)));
            }
        }
        out.flush();
        fft(p, mxsz, true);

        for(int i = 0; i < mxsz; ++i) {
            long x = (long)(Math.round(p.get(i).abs()));
            if(x == 0) continue;
            long g = gcd(x, denom);
            out.printf("%d %d/%d\n", i, x / g, denom / g);
        }
        out.flush(); 
    }
}
