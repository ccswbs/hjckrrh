# Link

The link can be count to the top 50 projects in Drupal installations and
provides a standard custom content field for links. With this module links can
be added easily to any content types and profiles and include advanced
validating and different ways of storing internal or external links and URLs. It
also supports additional link text title, site wide tokens for titles and title
attributes, target attributes, css class attribution, static repeating values,
input conversion, and many more.


## Requirements

This module requires no modules outside of Drupal core.


## Installation

Install as you would normally install a contributed Drupal module. For further
information, see
[Installing Drupal Modules](https://www.drupal.org/docs/extending-drupal/installing-drupal-modules).


## Configuration

- Configuration is only slightly more complicated than a text field. Link text
  titles for URLs can be made required, set as instead of URL, optional
  (default), or left out entirely. If no link text title is provided, the
  trimmed version of the complete URL will be displayed. The target attribute
  should be set to "_blank", "top", or left out completely (checkboxes provide
  info). The rel=nofollow attribute prevents the link from being followed by
  certain search engines. More info at
  [Wikipedia](https://en.wikipedia.org/wiki/Spam_in_blogs#rel.3D.22nofollow.22).


## Example

If you were to create a field named 'My New Link', the default display of the
link would be:

    <em><div class="field_my_new_link" target="[target_value]"><a href="[URL]">
    [Title]</a></div></em>

where items between [] characters would be customized based on the user input.

The link project supports both, internal and external URLs. URLs are validated
on input. Here are some examples of data input and the default view of a link:
`https://drupal.org` results in `https://drupal.org`, but drupal.org results in
`https://drupal.org`, while `<front>` will convert into `https://drupal.org` and
`node/74971` into `https://drupal.org/project/link`

Anchors and query strings may also be used in any of these cases, including:
`node/74971/edit?destination=node/74972<front>#pager`


## Theming and Output

Since link module is mainly a data storage field in a modular framework, the
theming and output is up to the site builder and other additional modules. There
are many modules in the Drupal repository, which control the output of fields
perfectly and can handle rules, user actions, markup dependencies, and can vary
the output under many different conditions, with much more efficience and
flexibility for different scenarios. Please check out modules like views,
display suite, panels, etc for such needs


## Maintainers

Current maintainers:

- [John C Fiala (jcfiala)](https://www.drupal.org/user/163643)
- [Renato Gonçalves (RenatoG)](https://www.drupal.org/user/3326031)
- [Clemens Tolboom (clemens.tolboom)](https://www.drupal.org/user/125814)
- [diqidoq](https://www.drupal.org/user/1001934)
- [dropcube](https://www.drupal.org/user/37031)
- [Tom Kirkpatrick (mrfelton)](https://www.drupal.org/user/305669)
- [Sumit Madan (sumitmadan)](https://www.drupal.org/user/1538790)
- [Daniel Kudwien (sun)](https://www.drupal.org/user/54136)
- [Damien McKenna](https://www.drupal.org/u/damienmckenna)
