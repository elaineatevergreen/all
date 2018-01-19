<?php

abstract class ArchivesMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);

    // Add database connection info
    Database::addConnectionInfo('for_migration', 'default', array(
      'driver' => 'mysql',
      'database' => 'at_db',
      'username' => 'danu',
      'password' => 'ev_archives!',
      'host' => '127.0.0.1',
      'port' => '33067',
      'prefix' => '',
    ));

    $this->team = array(
      new MigrateTeamMember('Randy Stilson', 'stilsonr@evergreen.edu',
                            t('Archivist')),
      new MigrateTeamMember('Naomi Touchet', 'touchetn@evergreen.edu',
                            t('Website')),
    );
  }
}
