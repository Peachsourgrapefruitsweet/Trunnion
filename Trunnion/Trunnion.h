#pragma once

#include <QtWidgets/QDialog>
#include <QSqlDatabase>
#include <unordered_map>
#include "ui_Trunnion.h"


struct MyHashFunction
{
	mutable std::map<std::string, size_t> indexs;
	std::size_t operator()(const std::string& key) const
	{
		std::map<std::string, size_t>::iterator iterator = indexs.find(key);
		if (iterator == indexs.end())
		{
			indexs[key] = indexs.size();
		}
		return indexs[key];
	}
};
class Trunnion : public QDialog
{
    Q_OBJECT

public:
    Trunnion(bool UsesHashData, std::unordered_map<std::string, std::string, MyHashFunction>& contrast, QWidget *parent = nullptr);
    ~Trunnion();
	//��������
	static bool DLG_data(bool UsesHashData, std::unordered_map<std::string, std::string, MyHashFunction>& contrast);

	//����contrastӳ��
	void useHashDate();
public slots:
	//ѡ��֧������
	void whileTypeA(bool status);
	void whileTypeB(bool status);
	void whileTypeC(bool status);
	//ѡ��֧�ȹ��
	void choiceDN(const QString &DN);
	//��������Բ
	void coputingCenterCircle();
	//���ȷ��
	void invoke();
private:
	Ui::TrunnionClass ui_;

	QSqlDatabase db_;//���ݿ�

	QString legType_ = "A";//֧������

	std::unordered_map<std::string, std::string, MyHashFunction>& contrast_;
};
