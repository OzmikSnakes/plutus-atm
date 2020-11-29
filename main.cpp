#include "controllers/login.h"
#include "controllers/cash_withdrawal.h"
#include "controllers/charge_account.h"
#include "controllers/transfer.h"
#include <QApplication>

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
#ifdef _DEBUG
    RestConfiguration config = RestConfiguration(false, "localhost:8080", "api", QSslConfiguration::defaultConfiguration());
#endif
#ifndef _DEBUG
	RestConfiguration config = RestConfiguration(true, "plutus-system.herokuapp.com", "api", QSslConfiguration::defaultConfiguration());
#endif
	Requester requester{config, SessionManager::getInstance()};
	CashWithdrawal cash_withdrawal{requester};
	ChargeAccount charge_account{requester};
	Transfer transfer{requester};
	Login login{ requester };
    Menu menu{requester, login, cash_withdrawal, charge_account, transfer};
	login.show();
	return QApplication::exec();
}
