CKEDITOR.on( 'dialogDefinition', function( ev ) {
    // Take the dialog name and its definition from the event data.
    var dialogName = ev.data.name;
    var dialogDefinition = ev.data.definition;

    if ( dialogName == 'link' ) {
        dialogDefinition.removeContents( 'target' );
    }

    if ( dialogName == 'table' || dialogName == 'tableProperties' ) {
        var infoTab = dialogDefinition.getContents( 'info' );
        infoTab.remove( 'txtWidth' );
        infoTab.remove( 'txtHeight' );
        infoTab.remove( 'txtCellPad' );
        infoTab.remove( 'txtCellSpace' );
        infoTab.remove( 'txtBorder' );
        var advTab = dialogDefinition.getContents( 'advanced' );
        var advCssClasses = advTab.get( 'advCSSClasses' );
        advCssClasses[ 'default' ] = 'table';
    }

    if ( dialogName == 'image' ) {
        var infoTab = dialogDefinition.getContents( 'info' );
        infoTab.remove( 'txtWidth' );
        infoTab.remove( 'txtHeight' );
        infoTab.remove( 'txtBorder' );
        infoTab.remove( 'ratioLock' );
	infoTab.remove( 'cmbAlign' );
	infoTab.remove( 'txtHSpace' );
	infoTab.remove( 'txtVSpace' );
        var advTab = dialogDefinition.getContents( 'advanced' );
        var classField = advTab.get( 'txtGenClass' );
        classField[ 'default' ] = 'img-responsive';
    }
});

/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if(typeof(CKEDITOR) !== 'undefined') {
    CKEDITOR.addStylesSet( 'drupal',
    [
            /* Object Styles */

            {
                    name : 'Image on Left',
                    element : 'img',
                    attributes :
                    {
                            'class' : 'pull-left gap-right'
                    }
            },

            {
                    name : 'Image on Right',
                    element : 'img',
                    attributes :
                    {
                            'class' : 'pull-right gap-left'
                    }
            },

	    {
		    name : 'Image Centered',
		    element : 'img',
		    attributes :
		    {
                            'class' : 'center-block'
		    }
	    }
    ]);
}
