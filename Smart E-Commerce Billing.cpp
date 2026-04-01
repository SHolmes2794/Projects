// Smart E-Commerce Billing.cpp

#include <iostream>
#include <string>
using namespace std;

class BillCalculator
{
	public:
		int calculateBill(int product_price, int shipping_charge)
		{
			return product_price + shipping_charge;
		}

		double calculateBill(double product_price, double tax_rate)
		{
			return product_price + (product_price * tax_rate);
		}

		double calculateBill(double product_price, double tax_rate, double discount)
		{
			return calculateBill(product_price, tax_rate) - discount;
		}
};

class PaymentMethod
{
	private:
		string customer_name;
		double amount;
		string transaction_id;

	public:
		void setPaymentDetails(string customer_name, double amount, string transaction_id)
		{
			this->customer_name = customer_name;
			this->amount = amount;
			this->transaction_id = transaction_id;
		}

		void displayPaymentDetails()
		{
			cout << "\n----- PAYMENT DETAILS -----" << endl;
			cout << " Customer Name: " << customer_name << endl;
			cout << " Transaction ID: " << transaction_id << endl;
			cout << " Payment Amount: " << amount << endl;
		}

		virtual void pay() = 0;
};

class UPIPayment : public PaymentMethod
{
	private:
		string upi_id;

	public:
		void setUPIDetails(string upi_id)
		{
			this->upi_id = upi_id;
		}

		void pay()
		{
			displayPaymentDetails();
			cout << " Payment Method: UPI" << endl;
			cout << " UPI ID: " << upi_id << endl;
			cout << " UPI Payment Successful" << endl;
			cout << "---------------------------" << endl;
		}
};

class CardPayment : public PaymentMethod
{
	private:
		string bank_name;

	public:
		void setCardDetails(string bank_name)
		{
			this->bank_name = bank_name;
		}
			
		void pay()
		{
			displayPaymentDetails();
			cout << " Payment Method: Card" << endl;
			cout << " Bank Name: " << bank_name << endl;
			cout << " Card Payment Successful" << endl;
			cout << "---------------------------" << endl;
		}
};

class WalletPayment : public PaymentMethod
{
	private:
		string wallet_name;

	public:
		void setWalletDetails(string wallet_name)
		{
			this->wallet_name = wallet_name;
		}

		void pay()
		{
			displayPaymentDetails();
			cout << " Payment Method: Wallet" << endl;
			cout << " Wallet Name: " << wallet_name << endl;
			cout << " Wallet Payment Successful" << endl;
			cout << "---------------------------" << endl;
		}
};

int main()
{
	string customer_name, bank_name, wallet_name, upi_id;
	int shipping_charge, product_price;
	double tax_rate, discount;

	cout << "Input Name: ";				getline(cin, customer_name);
	cout << "Input UPI ID: ";			getline(cin, upi_id);
	cout << "Input Bank Name: ";		getline(cin, bank_name);
	cout << "Input Wallet Name: ";		getline(cin, wallet_name);

	cout << "Input Product Price: ";	cin >> product_price;
	cout << "Input Tax Rate: ";			cin >> tax_rate;
	cout << "Input Discount: ";			cin >> discount;
	cout << "Input Shipping Charge: ";	cin >> shipping_charge;



	BillCalculator bill_object;
	int total_with_shipping = bill_object.calculateBill(product_price, shipping_charge);
	double total_with_tax = bill_object.calculateBill(double(product_price), tax_rate);
	double final_total = bill_object.calculateBill(double(product_price), tax_rate, discount);

	cout << "\n---------- BILL DETAILS ----------" << endl;
	cout << " Customer Name: " << customer_name << endl;
	cout << " Total (Product Price + Shipping): " << total_with_shipping << endl;
	cout << " Total (Product Price + Tax): " << total_with_tax << endl;
	cout << " Total (Product Price + Tax + Discount): " << final_total << endl;
	cout << "----------------------------------" << endl;



	PaymentMethod* payment_ptr;

	UPIPayment upi_object;
	upi_object.setPaymentDetails(customer_name, final_total, "TXN1001");
	upi_object.setUPIDetails(upi_id);

	CardPayment card_object;
	card_object.setPaymentDetails(customer_name, final_total, "TXN1002");
	card_object.setCardDetails(bank_name);

	WalletPayment wallet_object;
	wallet_object.setPaymentDetails(customer_name, final_total, "TXN1003");
	wallet_object.setWalletDetails(wallet_name);

	payment_ptr = &upi_object;
	payment_ptr->pay();

	payment_ptr = &card_object;
	payment_ptr->pay();

	payment_ptr = &wallet_object;
	payment_ptr->pay();

	return 0;
}