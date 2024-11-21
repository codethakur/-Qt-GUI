    #include "widget.h"
    #include <QTextEdit>
    #include <QLabel>
    #include <QVBoxLayout>
    #include<QPushButton>
    #include <QMenu>
    #include <QMenuBar>
    
    
    Widget::Widget(QWidget *parent)
        : QWidget(parent)
    {
        setupUi();
        //setFixedSize(400, 400);
    }
    
    Widget::~Widget() {}
    
    void Widget::setupUi()
    {
        // Create a layout to organize widgets
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
    
        // Create and add the label
        QLabel *label = new QLabel(this);
        label->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(label);
    
        // Create and add the text edit
        QTextEdit *textEdit = new QTextEdit(this);
        mainLayout->addWidget(textEdit);
    
        // Create a horizontal layout for the buttons
        QHBoxLayout *buttonLayout = new QHBoxLayout();
    
        // Create buttons and add them to the horizontal layout
        QPushButton *copyButton = new QPushButton("Copy", this);
        copyButton->setMinimumSize(30, 20);
        buttonLayout->addWidget(copyButton);
    
        QPushButton *pasteButton = new QPushButton("Paste", this);
        pasteButton->setMinimumSize(30, 20);
        buttonLayout->addWidget(pasteButton);
    
        QPushButton *cutButton = new QPushButton("Cut", this);
        cutButton->setMinimumSize(30, 20);
        buttonLayout->addWidget(cutButton);
    
        QPushButton *undoButton = new QPushButton("Undo", this);
        undoButton->setMinimumSize(30, 20);
        buttonLayout->addWidget(undoButton);
    
        QPushButton *redoButton = new QPushButton("Redo", this);
        redoButton->setMinimumSize(30, 20);
        buttonLayout->addWidget(redoButton);
    
        QPushButton *HTMLConvert = new QPushButton("HTML", this);
        HTMLConvert->setMinimumSize(30, 20);
        buttonLayout->addWidget(HTMLConvert);
    
        // Connect buttons to their respective slots
        connect(copyButton, &QPushButton::clicked, [=]() {
            textEdit->copy();
        });
        connect(pasteButton, &QPushButton::clicked, [=]() {
            textEdit->paste();
        });
        connect(cutButton, &QPushButton::clicked, [=]() {
            textEdit->cut();
        });
        connect(undoButton, &QPushButton::clicked, [=]() {
            textEdit->undo();
        });
        connect(redoButton, &QPushButton::clicked, [=]() {
            textEdit->redo();
        });
    
        connect(HTMLConvert, &QPushButton::clicked, [=]() {
            // Retrieve the current HTML content of the QTextEdit
            qInfo()<<"HTML::\n "<<textEdit->toHtml();
            QString htmlContent = textEdit->toHtml();
    
            // Directly set the HTML content back into the QTextEdit
            textEdit->setHtml(htmlContent);
        });
    
    
    
    
    
    
    
        // Add the horizontal layout to the main vertical layout
        mainLayout->addLayout(buttonLayout);
    
        // Set the layout for the widget
        setLayout(mainLayout);
    }
