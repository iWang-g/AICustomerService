#include "MainController.h"

#include "../models/PlatformModel.h"
#include "../views/MainWindowView.h"
#include "../views/AddWindowDialogView.h"

#include <QMessageBox>
#include <QStatusBar>

/**
 * @brief 构造函数，初始化控制器
 * @param parent 父对象
 */
MainController::MainController(QObject* parent)
    : QObject(parent)
    , m_view(new MainWindowView())           // 创建主窗口视图
    , m_platformModel(new PlatformModel(m_view))  // 创建平台数据模型
{
    // 将Model注入View，建立MVC连接
    m_view->setPlatformModel(m_platformModel);

    // 连接View信号到Controller槽函数
    connect(m_view, &MainWindowView::requestQuickStart, this, &MainController::onRequestQuickStart);
    connect(m_view, &MainWindowView::requestAutoEmbed, this, &MainController::onRequestAutoEmbed);
    connect(m_view, &MainWindowView::requestAdd, this, &MainController::onRequestAdd);
    connect(m_view, &MainWindowView::requestRefresh, this, &MainController::onRequestRefresh);
    connect(m_view, &MainWindowView::platformGroupClicked, this, &MainController::onPlatformGroupClicked);
    connect(m_view, &MainWindowView::platformSelected, this, &MainController::onPlatformSelected);
}

/**
 * @brief 响应快速启动请求
 */
void MainController::onRequestQuickStart()
{
    // 业务占位：实际应实现快速启动应用功能
    m_view->statusBar()->showMessage(QStringLiteral("点击：快速启动应用（未实现）"), 2000);
}

/**
 * @brief 响应自动嵌入请求
 */
void MainController::onRequestAutoEmbed()
{
    // 业务占位：实际应实现自动嵌入窗口功能
    m_view->statusBar()->showMessage(QStringLiteral("点击：自动嵌入窗口（未实现）"), 2000);
}

/**
 * @brief 响应添加请求
 */
void MainController::onRequestAdd()
{
    // 弹出"添加新窗口"对话框，暂不实现业务逻辑
    AddWindowDialogView dlg(m_view);
    dlg.exec();  // 模态显示对话框
}

/**
 * @brief 响应刷新请求
 */
void MainController::onRequestRefresh()
{
    // 业务占位：实际应实现刷新平台状态功能
    m_view->statusBar()->showMessage(QStringLiteral("点击：刷新（未实现）"), 2000);
}

/**
 * @brief 响应平台分组点击
 * @param row 点击的分组行索引
 */
void MainController::onPlatformGroupClicked(int row)
{
    Q_UNUSED(row);  // 暂未使用此参数
    // 分组点击已由View内部处理
}

/**
 * @brief 响应平台选择
 * @param id 选中的平台ID
 */
void MainController::onPlatformSelected(const QString& id)
{
    // 根据选择的平台ID更新状态栏消息
    if (id.isEmpty())
        m_view->statusBar()->showMessage(QStringLiteral("就绪"));
    else if (id == QLatin1String("online"))
        m_view->statusBar()->showMessage(QStringLiteral("在线平台"));
    else if (id == QLatin1String("qq"))
        m_view->statusBar()->showMessage(QStringLiteral("QQ"));
    else if (id == QLatin1String("workwechat"))
        m_view->statusBar()->showMessage(QStringLiteral("企业微信"));
    else if (id == QLatin1String("qianniu"))
        m_view->statusBar()->showMessage(QStringLiteral("千牛"));
    else
        m_view->statusBar()->showMessage(QStringLiteral("就绪"));
}
