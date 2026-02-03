#include "SettingDialog.h"
#include <QApplication>
#include <QFont>
#include <QSpacerItem>
#include <QScreen>

/**
 * @brief 逻辑简化编写，代码结构待重构
 */

SettingDialog::SettingDialog(QWidget *parent)
    : QDialog(parent)
{
    // Qt6 窗口属性设置（非模态，仅保留关闭按钮）
    setWindowModality(Qt::NonModal);
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowTitleHint);
    setWindowTitle(QStringLiteral("系统设置"));

    // Qt6 自适应屏幕比例，设置合理尺寸
    const QSize screenSize = qApp->primaryScreen()->availableSize();
    resize(screenSize.width() * 0.35, screenSize.height() * 0.55); // 自适应比例
    setMinimumSize(480, 380); // 最小尺寸限制

    // 构建UI
    buildUI();
}

QFrame* SettingDialog::makeCard(QWidget* parent)
{
    auto* card = new QFrame(parent);
    card->setObjectName("settingCard");
    card->setFrameShape(QFrame::NoFrame);
    // 匹配现有代码的卡片样式
    card->setStyleSheet(R"(
        QFrame#settingCard {
            background-color: #FFFFFF;
            border-radius: 10px;
        }
    )");
    return card;
}

void SettingDialog::buildUI()
{
    // 根布局（匹配现有代码的边距/间距风格）
    auto* rootLayout = new QVBoxLayout(this);
    rootLayout->setContentsMargins(20, 20, 20, 20);
    rootLayout->setSpacing(16);
    rootLayout->setAlignment(Qt::AlignTop);

    // 标题栏（Qt6 系统图标占位）
    auto* titleFrame = new QFrame(this);
    titleFrame->setObjectName("titleFrame");
    auto* titleLayout = new QHBoxLayout(titleFrame);
    titleLayout->setContentsMargins(0, 0, 0, 0);
    titleLayout->setSpacing(12);

    // 标题图标（Qt6 标准设置图标）
    auto* titleIcon = new QLabel(titleFrame);
    titleIcon->setFixedSize(24, 24);
    titleIcon->setPixmap(qApp->style()->standardIcon(QStyle::SP_FileDialogStart)
                             .pixmap(24, 24, QIcon::Normal, QIcon::On)); // Qt6 图标渲染参数

    // 标题文本（匹配现有代码的字体风格）
    auto* titleLabel = new QLabel(QStringLiteral("系统设置"), titleFrame);
    titleLabel->setObjectName("settingTitle");
    titleLabel->setStyleSheet(R"(
        QLabel#settingTitle {
            font-size: 16px;
            font-weight: bold;
            color: #282828;
        }
    )");

    titleLayout->addWidget(titleIcon);
    titleLayout->addWidget(titleLabel);
    titleLayout->addStretch(1);
    rootLayout->addWidget(titleFrame);

    // 分割线（匹配现有代码的分割线样式）
    auto* divider = new QFrame(this);
    divider->setObjectName("settingDivider");
    divider->setFixedHeight(1);
    divider->setStyleSheet(R"(
        QFrame#settingDivider {
            background-color: #EEEEEE;
            border-radius: 0.5px;
        }
    )");
    rootLayout->addWidget(divider);

    // 主内容卡片（仅UI占位）
    auto* contentCard = makeCard(this);
    auto* contentLayout = new QVBoxLayout(contentCard);
    contentLayout->setContentsMargins(24, 24, 24, 24);
    contentLayout->setSpacing(20);

    // 基础设置分组（占位）
    auto* basicGroup = new QLabel(QStringLiteral("▶ 基础设置"), contentCard);
    basicGroup->setStyleSheet(R"(
        QLabel {
            font-size: 14px;
            font-weight: bold;
            color: #404040;
        }
    )");
    contentLayout->addWidget(basicGroup);

    auto* basicTips = new QLabel(QStringLiteral("- 窗口布局 / 显示风格 / 语言设置"), contentCard);
    basicTips->setStyleSheet(R"(
        QLabel {
            font-size: 13px;
            color: #666666;
            margin-left: 16px;
            margin-top: 4px;
        }
    )");
    contentLayout->addWidget(basicTips);

    // 平台配置分组（占位）
    auto* platformGroup = new QLabel(QStringLiteral("▶ 平台配置"), contentCard);
    platformGroup->setStyleSheet(R"(
        QLabel {
            font-size: 14px;
            font-weight: bold;
            color: #404040;
            margin-top: 12px;
        }
    )");
    contentLayout->addWidget(platformGroup);

    auto* platformTips = new QLabel(QStringLiteral("- 多平台集成 / 自动启动 / 状态监控"), contentCard);
    platformTips->setStyleSheet(R"(
        QLabel {
            font-size: 13px;
            color: #666666;
            margin-left: 16px;
            margin-top: 4px;
        }
    )");
    contentLayout->addWidget(platformTips);

    // 快捷操作分组（占位）
    auto* quickGroup = new QLabel(QStringLiteral("▶ 快捷操作"), contentCard);
    quickGroup->setStyleSheet(R"(
        QLabel {
            font-size: 14px;
            font-weight: bold;
            color: #404040;
            margin-top: 12px;
        }
    )");
    contentLayout->addWidget(quickGroup);

    auto* quickTips = new QLabel(QStringLiteral("- 快捷键 / 快速启动 / 窗口嵌入"), contentCard);
    quickTips->setStyleSheet(R"(
        QLabel {
            font-size: 13px;
            color: #666666;
            margin-left: 16px;
            margin-top: 4px;
        }
    )");
    contentLayout->addWidget(quickTips);

    contentLayout->addStretch(1); // 伸缩空间推到底部
    rootLayout->addWidget(contentCard, 1); // 占满剩余空间

    // 底部按钮区（匹配现有代码的按钮样式）
    auto* btnFrame = new QFrame(this);
    auto* btnLayout = new QHBoxLayout(btnFrame);
    btnLayout->setContentsMargins(0, 0, 0, 0);
    btnLayout->setSpacing(12);
    btnLayout->setAlignment(Qt::AlignRight);

    // 取消按钮
    auto* cancelBtn = new QPushButton(QStringLiteral("取消"), btnFrame);
    cancelBtn->setObjectName("cancelBtn");
    cancelBtn->setFixedSize(90, 36);
    cancelBtn->setStyleSheet(R"(
        QPushButton#cancelBtn {
            background-color: #F5F5F7;
            border: none;
            border-radius: 8px;
            font-size: 14px;
            color: #333333;
        }
        QPushButton#cancelBtn:hover {
            background-color: #E8E8EB;
        }
        QPushButton#cancelBtn:pressed {
            background-color: #DFDFE2;
        }
    )");

    // 保存按钮（仅UI，无业务逻辑）
    auto* saveBtn = new QPushButton(QStringLiteral("保存设置"), btnFrame);
    saveBtn->setObjectName("saveBtn");
    saveBtn->setFixedSize(90, 36);
    saveBtn->setStyleSheet(R"(
        QPushButton#saveBtn {
            background-color: #409EFF;
            border: none;
            border-radius: 8px;
            font-size: 14px;
            color: #FFFFFF;
        }
        QPushButton#saveBtn:hover {
            background-color: #66B1FF;
        }
        QPushButton#saveBtn:pressed {
            background-color: #3390EE;
        }
    )");

    btnLayout->addWidget(cancelBtn);
    btnLayout->addWidget(saveBtn);
    rootLayout->addWidget(btnFrame);

    // 仅绑定关闭逻辑（无业务）
    connect(cancelBtn, &QPushButton::clicked, this, &SettingDialog::close);
    connect(saveBtn, &QPushButton::clicked, this, &SettingDialog::close);
}
