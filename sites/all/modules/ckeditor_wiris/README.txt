CONTENTS OF THIS FILE
---------------------
   
 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Maintainers

INTRODUCTION
------------

This module integrates WIRIS Editor into CKEditor. WIRIS is the leading equation editor for web-based platforms. It adds ability to insert math and chemistry equations — using MathType and ChemType — into your CKEditor.

WIRIS Editor generates the equation using [MathML](https://en.wikipedia.org/wiki/MathML), but it doesn't handle the rendering. In order to view the formula in your content, you must use a rendering solution such as [MathJax](https://www.drupal.org/project/mathjax).

REQUIREMENTS
------------

This module requires CKEditor module.

INSTALLATION
------------

Install the module [as usual](https://www.drupal.org/docs/7/extend/installing-modules).

CONFIGURATION
-------------

* Go to CKEditor settings (`admin/config/content/ckeditor`);
* Edit the profile you want to add the plugin;
* Drag the `MathType` and/or `ChemType` buttons from **available buttons** to the **current toolbar**;
* Enable the plugin CKEditor WIRIS.

MAINTAINERS
-----------

Current maintainers:

 * Thiago Régis (tregismoreira) - https://www.drupal.org/u/tregismoreira
 * Pierre Abrey (pierre@edumobi.com.br) - https://www.drupal.org/u/pierreedumobicombr
 * Ricardo Schneider (rarps) - https://www.drupal.org/u/rarps

This project has been sponsored by:

* **Somos Educação**. is Brazil’s largest basic education company and one of the largest educational groups in the world. SOMOS, in Portuguese, stands for “we are”, in English.

