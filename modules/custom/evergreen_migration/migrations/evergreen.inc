<?php

// extending the basic class, so there's a nice clean place to start from
// stolen wholesale from beer.inc in the Migrate examples!
// add any code that applies to ALL migrations.
abstract class EvergreenMigration extends Migration {
  // A Migration constructor takes an array of arguments as its first parameter.
  // The arguments must be passed through to the parent constructor.
  public function __construct($arguments) {
    parent::__construct($arguments);

    // With migrate_ui enabled, migration pages will indicate people involved in
    // the particular migration, with their role and contact info. We default the
    // list in the shared class; it can be overridden for specific migrations.
    $this->team = array(
      new MigrateTeamMember('Elaine Nelson', 'nelsone@evergreen.edu',
                            t('CMS Specialist')),
      new MigrateTeamMember('Justin McDowell', 'mcdowelj@evergreen.edu',
                            t('Front-end Developer')),
      new MigrateTeamMember('Susan Bustetter', 'bustetts@evergreen.edu',
                            t('Web Manager')),
    );
  }
  
  //if connecting to a db as part of the migration, maybe add that here.
  //see Migrate video series, ch 8, 10minute mark.
  
}