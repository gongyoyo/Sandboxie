#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SettingsWindow.h"

class CSettingsWindow : public QMainWindow
{
	Q_OBJECT

public:
	CSettingsWindow(QWidget *parent = Q_NULLPTR);
	~CSettingsWindow();

signals:
	void OptionsChanged();

public slots:
	void apply();
	void accept();
	void reject();

	void showCompat();

private slots:
	void OnChange();

	void OnTab();

	void OnSetPassword();

	void OnWarnChanged() { m_WarnProgsChanged = true; }
	void OnAddWarnProg();
	void OnAddWarnFolder();
	void OnDelWarnProg();

	void OnTemplateClicked(QTreeWidgetItem* pItem, int Column);
	void OnAddCompat();
	void OnDelCompat();

protected:
	void closeEvent(QCloseEvent *e);

	void	AddWarnEntry(const QString& Name, int type);

	int 	m_CompatLoaded;
	QString m_NewPassword;
	bool	m_WarnProgsChanged;
	bool	m_CompatChanged;
private:
	Ui::SettingsWindow ui;
};
