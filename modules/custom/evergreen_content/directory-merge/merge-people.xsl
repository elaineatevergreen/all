<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    version="1.0">
    
<!-- see page pg 41 of the O'Reilly XSLT book for how this is done -->

    <xsl:output omit-xml-declaration="yes" indent="yes"/>
    <!--<xsl:output indent="yes"/>-->
    
    <xsl:template match="people">
        <people>
        <xsl:for-each select="person">
            <xsl:sort select="email"/>

            <xsl:variable name="casname" select="email"/>
            
            <!-- groups together all the people with the same casname -->
            <xsl:if test="not(preceding-sibling::person[email=$casname])">
                <person casname="{email}">
                    <!-- these are the two fields shared across both feeds -->
                <xsl:copy-of select="name"/>
                <xsl:copy-of select="email"/>
                    <!-- get the fields unique to each feed -->
                <xsl:for-each select="/people/person[email=$casname]">
                    <!-- campus directory fields -->
                    <xsl:copy-of select="reference"/>
                    <xsl:copy-of select="title"/>
                    <xsl:copy-of select="location"/>
                    <xsl:copy-of select="mailstop"/>
                    <xsl:copy-of select="email_addressable"/>
                    <xsl:copy-of select="phone"/>
                    <xsl:copy-of select="phone_alt"/>
                    <xsl:copy-of select="fax"/>
                    <xsl:copy-of select="url"/>
                    <!-- faculty directory feeds -->
                    <xsl:copy-of select="isfaculty"/>
                    <xsl:copy-of select="expertise"/>
                    <xsl:copy-of select="bio"/>
                    <xsl:copy-of select="planning_unit"/>
                    <xsl:copy-of select="fields"/>
                    <xsl:copy-of select="full_bio"/>
                    <xsl:copy-of select="interest"/>
                </xsl:for-each>
                </person>
            </xsl:if>
        </xsl:for-each>
        </people>
    </xsl:template>
    
</xsl:stylesheet>