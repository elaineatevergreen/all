Migration Notes: wwwdev to wwwtest for policies migration

Created branch from master policies-feature
merge request from policies-feature to test branch

<-- WE ARE HERE

enable feature in modules

####################################################################################

create feeds importer: _Migration Upload: policies to www

Basic Settings:
    use standalone form
    import on submission
Fetcher
    File upload
Parser
    csv
Node Processor Settings:
    Approval Authority	Approval Authority (field_approval_authority)
    Approval Date	Approval Date (field_approval_date:start)
    Categories	Categories (Entity reference by Entity label) (field_categories:label)
    Archived	Archived (field_archived)
    Body	Body (body)   (Full HTML)
    Effective Date	Effective Date (field_effective_date:start)
    External Policy	External Policy: URL (field_external_policy:url)
    Prefix	Prefix (field_prefix)
    Signature File	Signature File: URI (field_signature_file:uri)  (rename if exists)
    Steward	Steward (field_steward)
    Stub	Stub (field_stub)
    Nid	GUID (guid)  (Used as unique)
    Title	Title (title)
    Related Documents	Related Documents: URI (field_related_documents:uri)
    Previous Version	Previous Version (Entity reference by Entity label) (field_previous_version:label)
    Related Policies	Related Policies (Entity reference by Entity label) (field_related_policies:label)
    Updated Version	Updated Version (Entity reference by Entity label) (field_updated_version:label)


Make sure you set the explode csv tamper for categories, signature file, related documents, previous version
Make sure you set the tamper for archived to:
    Find Replace Archived -> 1
    Find Replace Active -> 0

Set the Author to be carmichj
####################################################################################


Create _Migration Upload: Policies to www import
  import your test.csv (should be a straight download with no modification needed from http://collab.evergreen.edu/policies/admin/export/test)

Make sure the nodes come through cleanly (243 imported nodes total as of halloween)
  *Check to make sure the titles came through properly in content
  *Check to see that the links to pdfs came through (Mostly to make sure csv explodes work)
  *Check to see that the links to strange outside pages came through

  There should be one busted link, in "Student Conduct Code (archived February 2012)"
    http://search.leg.wa.gov/wslwac/WAC%20174%20%20TITLE/WAC%20174%20-120%20%20CHAPT... is a busted link that has no new equiv
    we can see here 174-120 is no longer available: http://apps.leg.wa.gov/documents/laws/WAC/WAC%20174%20%20TITLE/
###################################################################################

Create blocks (in content/blocks tab)
Section Background: Policies

####################################################################################
Taxonomies
  Current one on wwwdev
      Create taxonomy for "Policy Categories?
      Board of trustees
      Budget and Planning
      College Advancement
      Employment Policies
      Faculty Handbook
      Finance and Administration
      Governance and Grievance Procedures
      Health and Safety
      Planning Documents
      President's Office
      Student Affairs


####################################################################################
Create blocks (in content/blocks tab)
Section Navigation: Policies
  title: <none>
  view Mode: Default
  Section Navigation:
    Group Title: Policy Sections
    Board of Trustees      policy-categories/board-trustees
    Budget and Planning     policy-categories/budget-and-planning
    College Advancement     policy-categories/college-advancement
    Employment Policies     policy-categories/employment-policies
    Faculty Handbook        policy-categories/faculty-handbook
    Finance and Administration      policy-categories/finance-and-administration
    Governance and Grievance Procedures     policy-categories/governance-and-grievance-procedures
    Health and Safety     policy-categories/health-and-safety



###################################################################################
create our context
copy past the export from the old(er) context to the new one (in this case wwwdev to wwwtest)
  make sure the conditions has the taxonomy term "policy categories" added so they don't fight

###################################################################################
content type to the category page's view




don't forget to remove our test one and reupload the clean csv file

########################################

Fix redirects, sidebar links

Policies and Procedures
  Policies and Procedures Home
  A-Z Index
  Definitions
  Tools for Stewards

Related Links
  DTFs and Committees
  External Policy and Statute Resources
  Faculty Collective Bargaining Agreement
  WFSE Collective Bargaining Agreement
