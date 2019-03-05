/*
  ==============================================================================

    ModelNodeUI.cpp
    Created: 5 Mar 2019 11:17:25am
    Author:  bkupe

  ==============================================================================
*/

#include "ModelNodeUI.h"
#include "LightBlock/model/ui/LightBlockModelUI.h"

ModelNodeUI::ModelNodeUI(ModelNode * mn) :
	ColorNodeViewUI(mn),
	modelNode(mn),
	isDraggingItemOver(false)
{
}

ModelNodeUI::~ModelNodeUI()
{
}

void ModelNodeUI::paintOverChildren(Graphics & g)
{
	if (isDraggingItemOver)
	{
		g.setColour(BLUE_COLOR.withAlpha(.3f));
		g.fillRect(getMainBounds());
	}
}


bool ModelNodeUI::isInterestedInDragSource(const SourceDetails & source)
{
	return source.description.getProperty("type", "") == LightBlockModelUI::dragAndDropID.toString();
}

void ModelNodeUI::itemDragEnter(const SourceDetails & source)
{
	isDraggingItemOver = true;
	repaint();
}

void ModelNodeUI::itemDragExit(const SourceDetails & source)
{
	isDraggingItemOver = false;
	repaint();
}

void ModelNodeUI::itemDropped(const SourceDetails & source)
{
	LightBlockModelUI * modelUI = dynamic_cast<LightBlockModelUI *>(source.sourceComponent.get());

	if (modelUI != nullptr)
	{
		LightBlockColorProvider * provider = modelUI->item;

		bool shift = KeyPress::isKeyCurrentlyDown(16);
		if (shift)
		{
			PopupMenu m;
			m.addItem(-1, "Default");
			m.addSeparator();
			int index = 1;
			for (auto &p : modelUI->item->presetManager.items) m.addItem(index++, p->niceName);
			int result = m.show();
			if (result >= 1) provider = modelUI->item->presetManager.items[result - 1];
		}

		modelNode->activeProvider->setValueFromTarget(provider, true);
	}

	isDraggingItemOver = false;
	repaint();
}
