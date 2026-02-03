#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QStyle>

/**
 * @brief 设置对话框（仅UI，无业务逻辑）
 * 待重构优化
 */
class SettingDialog final : public QDialog
{
    Q_OBJECT
public:
    explicit SettingDialog(QWidget *parent = nullptr);

private:
    /**
     * @brief 构建对话框UI
     */
    void buildUI();

    /**
     * @brief 创建卡片容器（复用现有代码的卡片风格）
     * @param parent 父组件
     * @return 卡片Frame指针
     */
    QFrame* makeCard(QWidget* parent);
};

#endif // SETTINGDIALOG_H
