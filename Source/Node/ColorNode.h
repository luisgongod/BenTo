/*
  ==============================================================================

	ColorNode.h
	Created: 14 Apr 2018 1:00:32pm
	Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Node.h"

class ColorNode :
	public Node
{
public:
	ColorNode(const String &name, var params = var());
	virtual ~ColorNode();

	ColorSlot * mainColorsSlot;

	virtual Array<Colour> getColorsForProp(Prop * p);
	virtual NodeViewUI * createUI() override;
};