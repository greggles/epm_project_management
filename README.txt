epm_project_management is an "Enterprise Project Management" tool to help manage
"projects" in use within an "enterprise".

Glossary
========
"Projects" are used to identify "Project" nodes on drupal.org. Things like 
themes and modules.

"Enterprises" are just organizations, but this tool is most likely only a 
valuable tool to help communicate if you have a large number of Drupal site
builders, a separate security review team, and maybe your folks are distributed
geographically or you have high turnover/use consultants making it hard for
everyone to stay in agreement on which modules can or can't be used.

Inspiration
===========
See http://growingventuresolutions.com/node/1079

Data Structure
==============
Data is stored in a handful of tables.

* title, nid, vid in the {node} table where type = 'epm_project';
* Project name is content_type_epm_project.field_epm_project_shortname_value
* The two default flags will have unknown flag ID values, but their names are
  epm_approved_security and epm_in_use.
* The scraped meta-data is stored in epm_project_management_data

So, to find the ratio of open to closed bugs of projects that are "in use":

SELECT n.title, open_bug_count / closed_bug_count 
FROM epm_project_management_data epm INNER JOIN node n on epm.nid = n.nid 
INNER JOIN flag_content fc ON fc.content_type = 'node' AND fc.content_id = n.nid
INNER JOIN flags f ON fc.fid = f.fid WHERE f.name = 'epm_in_use';

You could shorten that query up a bit by first finding the flagid:

SELECT fid FROM flags f WHERE f.name = 'epm_in_use';

On a fresh installation that should be 2.

Then reduce the query:

SELECT n.title, open_bug_count / closed_bug_count 
FROM epm_project_management_data epm INNER JOIN node n on epm.nid = n.nid 
INNER JOIN flag_content fc ON fc.content_type = 'node' AND fc.content_id = n.nid
WHERE fc.fid = 2;

And depending on the audience you should always add a WHERE clause for 
published nodes:

AND n.status = 1;


Development
===========
Greg Knaddison of Growing Venture Solutions http://growvs.com
Tell me how much you love the module @greggles on Twitter.
Tell me about problems or ideas in the issue queue (ideally with patches!)

