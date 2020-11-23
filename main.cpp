#include "controllers/login.h"
#include <QApplication>

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
#ifdef _DEBUG
	RestConfiguration config = RestConfiguration(false, "localhost:8080", "api", QSslConfiguration::defaultConfiguration());
#endif
	Requester requester{config, SessionManager::getInstance()};
	CashWithdrawal cash_withdrawal{requester};
	ChargeAccount charge_account{requester};
	CreditLimit credit_limit{requester};
	Transfer transfer{requester};
	Menu menu{requester, cash_withdrawal, charge_account, credit_limit, transfer};
	Login login{requester, menu};
	login.show();
	return QApplication::exec();
}
