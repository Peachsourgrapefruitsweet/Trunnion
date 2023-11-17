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
	//创建函数
	static bool DLG_data(bool UsesHashData, std::unordered_map<std::string, std::string, MyHashFunction>& contrast);

	//根据contrast映射
	void useHashDate();
public slots:
	//选择支腿类型
	void whileTypeA(bool status);
	void whileTypeB(bool status);
	void whileTypeC(bool status);
	//选择支腿规格
	void choiceDN(const QString &DN);
	//计算中心圆
	void coputingCenterCircle();
	//点击确定
	void invoke();
private:
	Ui::TrunnionClass ui_;

	QSqlDatabase db_;//数据库

	QString legType_ = "A";//支腿类型

	std::unordered_map<std::string, std::string, MyHashFunction>& contrast_;
};
