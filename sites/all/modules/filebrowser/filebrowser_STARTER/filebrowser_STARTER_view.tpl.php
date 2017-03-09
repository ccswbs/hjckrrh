<div style='background-color:#EEEEEE'>
<?php
	echo "Well, we have <b>".count($node->file_listing)."</b> files in this node....";
?>
<ul>
<?php 	
	foreach ($node->file_listing as $filename=>$file) {
		 $thumbnail = _filebrowser_thumbnails_generate($node, $file);
?>
	<li>
		<?php echo $thumbnail?> 
		<a href="<?php echo $file['url']?>">
			<?php echo $file['display-name']; ?>
		</a>
	</li>
<?php 			
	}
?>
</ul>
</div>