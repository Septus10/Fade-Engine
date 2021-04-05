/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include <GUI/Gwen.h>
#include <GUI/Controls/PropertyTree.h>
#include <GUI/Skin.h>

namespace Gwen
{
	namespace Controls
	{

		Properties* PropertyTree::Add( const TextObject & text )
		{
			TreeNode* node = new PropertyTreeNode( this );
			node->SetText( text );
			node->Dock( Pos::Top );
			Properties* props = new Properties( node );
			props->Dock( Pos::Top );
			return props;
		}

		Properties* PropertyTree::Find( const TextObject & text )
		{
			Controls::Base::List & children = GetChildNodes();

			for ( Base::List::iterator iter = children.begin(); iter != children.end(); ++iter )
			{
				PropertyTreeNode* pChild = gwen_cast<PropertyTreeNode> ( *iter );

				if ( !pChild ) { continue; }

				if ( pChild->GetText() == text )
				{
					Base::List & nodechildren = pChild->GetChildren();

					for ( Base::List::iterator iter = nodechildren.begin(); iter != nodechildren.end(); ++iter )
					{
						Properties* pPropertyChild = gwen_cast<Properties> ( *iter );

						if ( !pPropertyChild ) { continue; }

						return pPropertyChild;
					}
				}
			}

			return NULL;
		}
	}
}