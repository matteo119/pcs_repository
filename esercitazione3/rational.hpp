#include <iostream>
#include <concepts>
template<typename I> requires std::integral<I>
class rational {
	I num_;
	I den_;
private:

	void riduci() {
		I a = num_, b = den_, resto;
		while (b != 0) { //algoritmo di euclide per trovare mcd
			resto = a%b;
			a = b;
			b = resto;
		}
		if (den_ == 0 && a<0) { //preservo il segno di +/-inf
			a *= -1;
		}
		if (a != 0) { //semplifico la frazione, oss: se la frazione vale 0/n (n!=0) diventa 0/1 (analoghe oss con +/-inf)
			num_ /= a;
			den_ /= a;
		}
		if (den_ < 0) { //metto il segno a numeratore
			den_ *= -1;
			num_ *= -1;
		}
	}
	
public:
	
    bool is_nan() const {
        return den_ == 0 && num_ == 0;
    }
    bool is_pinf() const {
        return den_ == 0 && num_ > 0;
    }
	bool is_minf() const {
        return den_ == 0 && num_ < 0;
    }
    
	rational() : num_(0), den_(1) {}
    rational(I num, I den) : num_(num), den_(den) {
		riduci();
	}

    I num() const {
        if (is_nan()) {
            std::cout << "(il seguente 0 è nan) ";
        }
        if (is_pinf()) {
            std::cout << "(il seguente 1 è +inf) ";
        }
		if (is_minf()) {
            std::cout << "(il seguente -1 è -inf) ";
        }
        return num_;
    }
    I den() const {
        if (is_nan()) {
            std::cout << "(il seguente 0 è nan) ";
        }
        if (is_pinf()) {
            std::cout << "(il seguente 0 è +inf) ";
        }
		if (is_minf()) {
            std::cout << "(il seguente 0 è -inf) ";
        }
        return den_;
    }
	
	rational& operator+=(const rational& other) {
		if ((is_pinf() && other.is_minf()) || (is_minf() && other.is_pinf())) {			//rmk: is_pinf() è equivalente a this->is_pinf
			num_ = 0;
			return *this;							//+inf + -inf = nan ; -inf + +inf = nan
		}
		if ((is_pinf() && other.is_pinf()) || (is_minf() && other.is_minf())) {
			return *this;                   		//+inf + +inf = +inf ; -inf + -inf = -inf
		}
		num_ = num_*other.den_ + other.num_*den_;
		den_ *= other.den_;
		riduci();
		return *this;
	}
	rational operator+(const rational& other) const {
		rational ret = *this;
		ret += other;
		return ret;
	}
	rational& operator*=(const rational& other) {
		if ((is_pinf() && other.is_minf()) || (is_minf() && other.is_pinf())) {
			num_ = 0;
			return *this;							//+inf * -inf = nan ; -inf * +inf = nan
		}
		den_ *= other.den_;
		num_ *= other.num_;
		riduci();
		return *this;
	}
	rational operator*(const rational& other) const {
		rational ret = *this;
		ret *= other;
		return ret;
	}
	rational& operator-=(const rational& other) {
		if ((is_pinf() && other.is_minf()) || (is_minf() && other.is_pinf())) {
			return *this;							//+inf - -inf = +inf ; -inf - +inf = -inf
		}
		if ((is_pinf() && other.is_pinf()) || (is_minf() && other.is_minf())) {
			num_ = 0;
			return *this;							//+inf - +inf = nan ; -inf - -inf = nan
		}
		num_ = num_*other.den_ - other.num_*den_;
		den_ *= other.den_;
		riduci();
		return *this;
	}
	rational operator-(const rational& other) const {
		rational ret = *this;
		ret -= other;
		return ret;
	}
	rational& operator/=(const rational& other) {
		if (den_ == 0 && other.num_ < 0) { //(con n negativo) assegna il giusto segno a (+/-inf) / n = (-/+inf)
			num_ *= -1;
		}
		if (den_ == 0 && other.num_ == 0) { //(+/-inf) / 0 = nan
			num_ = 0;
		}
		den_ *= other.num_;
		num_ *= other.den_;
		riduci();
		return *this;
	}
	rational operator/(const rational& other) const {
		rational ret = *this;
		ret /= other;
		return ret;
	}

};

template<std::integral I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.is_nan()) {
        os << "nan";
        return os;
    }
    if (r.is_pinf()) {
        os << "+inf";
        return os;
    }
	if (r.is_minf()) {
        os << "-inf";
        return os;
    }
    os << r.num();
	if (r.den() != 1 && r.num() != 0) { //se r è un naturale stampa solo il numeratore
		os << "/" << r.den();
	}
    return os;
}







