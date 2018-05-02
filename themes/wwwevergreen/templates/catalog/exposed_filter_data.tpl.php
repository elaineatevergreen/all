<?php
/**
 * @file
 * Basic template file
 */
 
 /*
filters:
	year - Academic Year
	type: Offering Type
	offered: Quarters Offered
	quarters: Quarters Open to New Students (if "All" don't show info)
	standing: Class Standing (if "All" don't show info)
	credit_range: Credits Offered (rework to have range with dash)
	subject: Fields of Study (if "All" don't show info)
	location: Location (if "All" don't show info)
	internship: Internship Opportunities (if "All" don't show info)
	research: Research Opportunities  (if "All" don't show info)
	studyabroad: Study Abroad (if "All" don't show info)
	upperdivision: Upper Division Science Opportunities (if "All" don't show info)
*/
 
?>
<?php if (isset($exposed_filters)): ?>
  <div class="exposed_filter_data">
    <div class="title"><?php print t('Current Catalog Filter'); ?></div>
    <div class="content">
      <?php foreach ($exposed_filters as $filter => $value): ?>
        <?php if ($value and $value != 'All'): ?>
          <div class="filter"><div class="name"><?php print $filter; ?>: </div>
          <?php if (is_array($value)): ?>
            <div class="value">
<?php 
	if($filter == 'credit_range') { 
		print implode('–', $value);
	} else {
		print implode(', ', $value);
	};
	 
?>
			</div>
          <?php else: ?>
            <div class="value"><?php print $value; ?></div>
          <?php endif; ?>
          </div>
        <?php endif; ?>
      <?php endforeach; ?>
    </div>
  </div>
<?php endif; ?>
