/*  ObjectEditor.h
 *
 *  Copyright (C) 2013  Jim Evins <evins@snaught.com>
 *
 *  This file is part of gLabels-qt.
 *
 *  gLabels-qt is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gLabels-qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with gLabels-qt.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ObjectEditor_h
#define ObjectEditor_h

#include "ui_ObjectEditor.h"
#include "libglabels/Distance.h"

// Forward references
class LabelModel;
class LabelModelObject;
class UndoRedoModel;
	

///
/// Object Editor Widget
///
class ObjectEditor : public QWidget, public Ui_ObjectEditor
{
	Q_OBJECT

		
	/////////////////////////////////
	// Life Cycle
	/////////////////////////////////
public:
	ObjectEditor( QWidget *parent = 0 );


	/////////////////////////////////
	// Public methods
	/////////////////////////////////
	void setModel( LabelModel* model, UndoRedoModel* undoRedoModel );


	/////////////////////////////////
	// Private methods
	/////////////////////////////////
private:
	void hidePages();
	void loadImagePage();
	void loadLineFillPage();
	void loadPositionPage();
	void loadRectSizePage();
	void loadLineSizePage();
	void loadShadowPage();


	/////////////////////////////////
	// Slots
	/////////////////////////////////
private slots:
	void onSettingsChanged();
	void onLabelSizeChanged();
	void onSelectionChanged();
	void onMergeSourceChanged();
	void onObjectChanged();
	void onObjectMoved();
	void onObjectDestroyed();
	void onLineControlsChanged();
	void onFillControlsChanged();
	void onImageFileButtonClicked();
	void onPositionControlsChanged();
	void onRectSizeControlsChanged();
	void onLineSizeControlsChanged();
	void onShadowControlsChanged();
	void onChanged();
		

	/////////////////////////////////
	// Private data
	/////////////////////////////////
private:
	LabelModel*              mModel;
	LabelModelObject*        mObject;
	UndoRedoModel*           mUndoRedoModel;
	
	glabels::Units           mUnits;
	int                      mSpinDigits;
	double                   mSpinStep;
	
	bool                     mBlocked;

};


#endif // ObjectEditor_h
