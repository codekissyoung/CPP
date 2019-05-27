#ifndef CPP_BRASS_MODEL_H
#define CPP_BRASS_MODEL_H

#include <iostream>
#include <string>

class BrassBase{
protected:
    std::string fullName;   // 客户姓名
    long acctNum;           // 账号
    double balance;         // 资金结余
public:
    BrassBase( std::string s, long an, double bal ) : fullName{std::move(s)}, acctNum{an}, balance{bal} { }

    // 存款
    void Deposit( double amt ){
        balance += amt;
        std::cout << fullName << " 存入 " << amt << " 余额：" << balance << std::endl;
    }

    // 提现
    virtual void Withdraw( double amt ){
        if( amt <= balance )
        {
            balance -= amt;
            std::cout << fullName << " 取出 " << amt << " 余额：" << balance << std::endl;
        }else{
            std::cout << "您的余额不足" << std::endl;
        }
    };

    virtual void ViewAcct() const {

    }

    double Balance() const{
        return balance;
    }

    virtual ~BrassBase() {};

};

class Brass : public BrassBase{

public:
    Brass( std::string s, long an, double bal ) : BrassBase( std::move(s), an, bal ) {}

    ~Brass() override = default;

    void ViewAcct() const override {
        std::cout << "姓名: " << fullName << std::endl;
        std::cout << "账号: " << acctNum << std::endl;
        std::cout << "余额: " << balance << std::endl;
    }
};

class BrassPlus : public BrassBase {
private:
    double maxLoan;     // 贷款上限
    double rate;        // 贷款费率
    double owesBank;    // 欠款金额
public:
    BrassPlus(const std::string &s, long an, double bal, double ml, double r ) :
            BrassBase{s,an,bal}, maxLoan{ml}, rate{r}, owesBank{0.0} { }

    BrassPlus(const Brass &ba, double ml, double r ) :
            BrassBase{ba}, maxLoan{ml}, rate{r}, owesBank{0.0} { }

    ~BrassPlus() override = default;

    void ViewAcct() const override{
        std::cout << "VIP客户: " << fullName << std::endl;
        std::cout << "账号: " << acctNum << std::endl;
        std::cout << "余额: " << balance << std::endl;
        std::cout << "贷款上限：" << maxLoan << std::endl;
        std::cout << "贷款费率: " << rate << std::endl;
        std::cout << "欠款金额: " << owesBank << std::endl;
    }

    void Withdraw( double amt ) override{
        if( amt <= Balance() )
        {
            BrassBase::Withdraw( amt );
        }
        else if( amt <= Balance() + maxLoan - owesBank )
        {
            double advance = amt - Balance();

            owesBank += advance * (1.0 + rate);

            Deposit( advance );

            BrassBase::Withdraw( amt );
        }
        else
        {
            std::cout << "贷款金额超额" << std::endl;
        }
    }

    void ResetMax( double m ) { maxLoan = m; }
    void ResetRate( double r ) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif //CPP_BRASS_MODEL_H
