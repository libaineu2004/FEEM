#include "pf_actioninterface.h"
#include "pf_graphicview.h"

PF_ActionInterface::PF_ActionInterface(PF_GraphicView *view)
    :PF_Snapper(view)
{

}

void PF_ActionInterface::setName(const char *_name)
{

}

QString PF_ActionInterface::getName()
{

}

void PF_ActionInterface::init(int status)
{

}

void PF_ActionInterface::mouseMoveEvent(QMouseEvent *)
{

}

void PF_ActionInterface::mousePressEvent(QMouseEvent *)
{

}

void PF_ActionInterface::mouseReleaseEvent(QMouseEvent *)
{

}

void PF_ActionInterface::keyPressEvent(QKeyEvent *e)
{

}

void PF_ActionInterface::keyReleaseEvent(QKeyEvent *e)
{

}

void PF_ActionInterface::trigger()
{

}

void PF_ActionInterface::finish()
{

}

void PF_ActionInterface::suspend()
{

}

void PF_ActionInterface::resume()
{

}

bool PF_ActionInterface::isFinished()
{
    return finished;
}

void PF_ActionInterface::setFinished()
{
    status = -1;
}