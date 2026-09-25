#include <iomanip>
#include <iostream>

using namespace std;

// pass in space-delimited arguments when you call the executable
// Example: ./a.out 1 2 3.3
int main(int argc, char *argv[]) {
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  if (argc > 4) {
    cout << "Too many arguments. Cannot pass in more than three." << endl;
    return -1;
  }

  int i = 1;
  double loan_amount, yearly_interest_rate, monthly_payment;

  double arguments[3];

  if (argc > 1) {
    while (i < argc) {

      try {
        arguments[i - 1] = stod(argv[i]);
      } catch (const std::invalid_argument &) {
        if (i == 1)
          cout << "(Invalid loan amount): " << argv[i] << endl;
        else if (i == 2)
          cout << "(Invalid interest rate): " << argv[i - 1] << " " << argv[i]
               << endl;
        else
          cout << "(Invalid payment): " << argv[i - 2] << " " << argv[i - 1]
               << " " << argv[i] << endl;
        return -2;
      }
      i++;
    }
    loan_amount = arguments[0];
    yearly_interest_rate = arguments[1];
    monthly_payment = arguments[2];

  } else {
    cout << "Loan Amount: ";
    cin >> loan_amount;
    while (loan_amount <= 0) {
      cout << "Loan amount must be positive.\n";
      cout << "Loan Amount: ";
      cin >> loan_amount;
    }

    cout << "Interest Rate (% per year): ";
    cin >> yearly_interest_rate;
    while (yearly_interest_rate <= 1) {
      cout << "Interest rate must be positive.\n";
      cout << "Interest Rate (% per year): ";
      cin >> yearly_interest_rate;
    }

    cout << "Monthly Payments: ";
    cin >> monthly_payment;
    while (monthly_payment < (loan_amount * yearly_interest_rate / 12 / 100)) {
      cout << "Monthly payment too low, loan will never be repaid.\n";
      cout << "Loan Amount: ";
      cin >> monthly_payment;
    }

    cout << loan_amount << '\t' << yearly_interest_rate << '\t'
         << monthly_payment << endl;
  }

  int current_month = 0;
  double monthly_interest_rate = yearly_interest_rate / 12 / 100;

  double interest_paid, principle_paid;
  double total_interest_paid = 0;

  cout << "*****************************************************************\n"
       << "\tAmortization Table\n"
       << "*****************************************************************\n"
       << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"
       << "0\t$" << loan_amount << "\tN/A\tN/A\tN/A\t\tN/A\n";

  while (loan_amount > 0) {
    current_month++;
    interest_paid = loan_amount * monthly_interest_rate;
    total_interest_paid += interest_paid;

    if (interest_paid > monthly_payment) {
      throw runtime_error("Interest due is greater than monthly payment, the "
                          "loan will never be paid off.");
    }

    principle_paid = monthly_payment - interest_paid;
    loan_amount = loan_amount - principle_paid;
    if (loan_amount <= 0) {
      monthly_payment = monthly_payment + loan_amount;
      principle_paid = principle_paid + loan_amount;
      loan_amount = 0;
    };

    cout << left << setw(8) << current_month << "$" << setw(15) << loan_amount
         << "$" << setw(7) << monthly_payment << setw(8) << noshowpoint
         << defaultfloat << monthly_interest_rate * 100 << fixed << showpoint
         << "$" << setw(15) << interest_paid << "$" << setw(9) << principle_paid
         << endl;
  }

  cout << "****************************************************************\n";
  cout << "\nIt takes " << current_month << " months to pay off "
       << "the loan.\n"
       << "Total interest paid is: $" << total_interest_paid;

  cout << endl << endl;

  return 0;
}
