-- SUMMARY --

Lumturio offers agencies powerful and reliable tools to monitor CMS security.
As such, our platform empowers you to quickly and efficiently monitor all your
clients’ websites, allowing you to proactively update them and keep them safe.

The System Status module offers a way to collect data from Drupal websites
 to check on modules and versions used, instead of having every Drupal site
check for updates separately.

This allows administrators to build their own monitoring interface to 
check on multiple installations at once.

-- REQUIREMENTS --

PHP 5.2.5 or higher (5.3 recommended)
mcrypt


-- INSTALLATION --

Project URL: http://drupal.org/project/system_status/
GitURL: git clone http://git.drupal.org:project/system_status.git
Download and install the module the same way you would download and
install other contributed modules.


-- INSTALLATION USING DRUSH --

drush dl system_status
drush en system_status


-- USAGE --

After installation check the admin page under
/admin/config/system/system_status and copy your siteUUID.

-- FAQ --
1. Why do I need to install a module on my Drupal site?
The default update monitor build into Drupal works by each site checking
for updates triggered by a cron job. Our service works the oppisite way,
we will contact your site and ask for the currently installed modules and their
versions. We will then compare this to our database of Drupal contrib modules 
and calculate an upgrade path for you if required.

2. How can I be sure that my data is secure?
Lumturio uses SHA256 and supports TLS 1.2 for all communication with
and from the platform and uses the DHE-RSA Key Exchange Algorithm.
Passwords are encrypted through unique salts per account, using the SHA512 algorithm.
We monitor the security community's output closely and work promptly to
upgrade the service to respond to new vulnerabilities as they are discovered.

3. How will you use this data that I provide?
The drupal module itself will always be reviewed and worked on by the Drupal community
to ensure that it only delivers a list of currently used modules and their versions.
No other data is or will ever be transmitted.

4. Who can I get in touch with if I have questions?
You are welcome to send an e-mail to hello@lumturio.com, we will do our best to 
respond as soon as possible.

5. I have a feature request, what should i do?
All feature requests are welcome, feel free to send us an e-mail on hello@lumturio.com.
No promises are made, but we will definitely look into it.

6. I like this project, can I help?
We're always looking for enthousiastic souls that want to help make this project better.
If you feel you have something to contribute, contact us by e-mail at hello@lumturio.com.
