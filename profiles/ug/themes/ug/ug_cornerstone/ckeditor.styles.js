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
        advCssClasses[ 'default' ] = 'table table-responsive';
    }

    if ( dialogName == 'image' ) {
        var infoTab = dialogDefinition.getContents( 'info' );
        infoTab.remove( 'txtWidth' );
        infoTab.remove( 'txtHeight' );
        infoTab.remove( 'txtBorder' );
        infoTab.remove( 'ratioLock' );
        var advTab = dialogDefinition.getContents( 'advanced' );
        var classField = advTab.get( 'txtGenClass' );
        classField[ 'default' ] = 'img-responsive';
    }
});
