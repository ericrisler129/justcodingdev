-- About --

Quiz questions import (qq_import) is a simple module, designed as an
addon for quiz module. It allows user with specific permission to create
a bulk of quiz questions from CSV file. The import CSV file must be in
format specified in 'examples' directory.

-- How to use --

* This module has been developed to work on top of Feeds module. So Feeds and
its dependencies need to be enabled to ensure the proper working of qq_import.

* Login as Administrator user to your Drupal site and open the feeds default
Import page at path /import (eg. http://example.com/import)

* Separate importer per question type can be noted. Once the importer link is
clicked, form to upload the questions from CSV file will be shown.

* As of now the import source file need to have only one question type at once and
it should be in the format mentioned in 'examples' folder.

* If the import file is not clear, read the importer description mentioned in
Home > Administration > Structure > Feeds importers
(path http://example.com/admin/structure/feeds)

* To set the default values for multichoice question during the import use the
settings form at http://example.com/admin/quiz/import

-- Advance option --

* If you are already familiar with Feeds configuration then importer settings
can be changed as needed from Home > Administration > Structure > Feeds importers
(path http://example.com/admin/structure/feeds).


-- How it is different from existing import module --

Proposed module is a subset of existing import module developed for
one of our recent projects.

Existing module supports many import types but nothing works
out-of-box. Handling multiple import types made validation and
submit handler tricky and hard to customize for project specific
needs.

Proposed module supports only CSV import. Import file can have only
one type of questions (either multichoice, truefalse or similar).

The code is posted in drupal.org with an intention of sharing.

For a full description of the module, visit the project page:
  http://drupal.org/project/qq_import

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/qq_import


-- REQUIREMENTS --

This module depends of quiz and Feeds. To use this module you need to enable,
the quiz module and one of its questions type module (multichoice,
long_answer, etc.)


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- CONTACT --

Current maintainer:
* Sivaji - http://drupal.org/user/328724

-- CREDIT --

This module has been developed and maintained by Sivaji at KnackForge -
The Drupal shop operating from Chennai, India. KnackForge offers
Drupal development, consultancy, hosting and support to customers
worldwide. Check out http://knackforge.com or Write to
support@knackforge.com to know more.


