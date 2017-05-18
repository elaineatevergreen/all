<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    version="1.0">
    
    <xsl:output omit-xml-declaration="yes"  indent="yes"/>
    <!--<xsl:output indent="yes"/>-->
    
    <xsl:template match="instructors">
        <people>
        <xsl:for-each select="faculty">
            <person>
                <!-- this should make setting the flag in Drupal easier -->
                <isfaculty>yes</isfaculty>
                <xsl:copy-of select="name"/>
                <email><xsl:value-of select="@user_name"/></email>
                <xsl:copy-of select="expertise"/>
                <xsl:copy-of select="bio"/>
                <xsl:copy-of select="planning_unit"/>
                <xsl:copy-of select="fields"/>
                <xsl:copy-of select="full_bio"/>
                <xsl:copy-of select="interest"/>
            </person>
            
        </xsl:for-each>
        </people>
    </xsl:template>
    
    
</xsl:stylesheet>