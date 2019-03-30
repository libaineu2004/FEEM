#include "navigationtreeview.h"

#include <QFocusEvent>
#include <QHeaderView>
#include <QScrollBar>

NavigationTreeView::NavigationTreeView(QWidget *parent)
    : TreeView(parent)
{
    setFrameStyle(QFrame::NoFrame);
    setIndentation(indentation() * 9/10);
    setUniformRowHeights(true);
    setTextElideMode(Qt::ElideNone);
    setAttribute(Qt::WA_MacShowFocusRect, false);

    setHeaderHidden(true);
    // We let the column adjust to contents, but note
    // the setting of a minimum size in resizeEvent()
    header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    header()->setStretchLastSection(false);
}

void NavigationTreeView::scrollTo(const QModelIndex &index, QAbstractItemView::ScrollHint hint)
{
    // work around QTBUG-3927
    QScrollBar *hBar = horizontalScrollBar();
    int scrollX = hBar->value();

    const int viewportWidth = viewport()->width();
    QRect itemRect = visualRect(index);

    QAbstractItemDelegate *delegate = itemDelegate(index);
    if (delegate)
        itemRect.setWidth(delegate->sizeHint(viewOptions(), index).width());

    if (itemRect.x() - indentation() < 0) {
        // scroll so left edge minus one indent of item is visible
        scrollX += itemRect.x() - indentation();
    } else if (itemRect.right() > viewportWidth) {
        // If right edge of item is not visible and left edge is "too far right",
        // then move so it is either fully visible, or to the left edge.
        // For this move the left edge one indent to the left, so the parent can potentially
        // still be visible.
        if (itemRect.width() + indentation() < viewportWidth)
            scrollX += itemRect.right() - viewportWidth;
        else
            scrollX += itemRect.x() - indentation();
    }
    scrollX = qBound(hBar->minimum(), scrollX, hBar->maximum());
    TreeView::scrollTo(index, hint);
    hBar->setValue(scrollX);
}

// This is a workaround to stop Qt from redrawing the project tree every
// time the user opens or closes a menu when it has focus. Would be nicer to
// fix it in Qt.
void NavigationTreeView::focusInEvent(QFocusEvent *event)
{
    if (event->reason() != Qt::PopupFocusReason)
        TreeView::focusInEvent(event);
}

void NavigationTreeView::focusOutEvent(QFocusEvent *event)
{
    if (event->reason() != Qt::PopupFocusReason)
        TreeView::focusOutEvent(event);
}

void NavigationTreeView::resizeEvent(QResizeEvent *event)
{
    const int columns = header()->count();
    const int minimumWidth = columns > 1 ? viewport()->width() / columns
                                         : viewport()->width();
    header()->setMinimumSectionSize(minimumWidth);
    TreeView::resizeEvent(event);
}
