DELETE FROM `command` WHERE `id` IN (810, 811);
INSERT INTO `command` (`id`, `command_text`, `security`, `help_text`) VALUES 
(810, 'cheat', 2, 'Syntax: .cheat $subcommand\r\nType .cheat to see the list of possible subcommands or .help cheat $subcommand to see info on subcommands'),
(811, 'cheat god', 2, 'Syntax: .cheat god [on/off]\r\nEnables or disables your character''s ability to take damage.');

DELETE FROM `mangos_string` WHERE `entry` IN (1717, 1718);
INSERT INTO `mangos_string` (`entry`, `content_default`, `content_loc3`, `source_file`, `source_enum_wrapper`, `source_enum_tag`) VALUES
(1717, 'Godmode is ON. You won\'t take damage.', 'GottModus eingeschalten. Du bekommst keinen Schaden.', 'Language.h', 'MangosString', 'LANG_CHEAT_ON'),
(1718, 'Godmode is OFF. You can take damage.', 'GottModus ausgeschalten. Du bekommst wieder Schaden.', 'Language.h', 'MangosString', 'LANG_CHEAT_OFF');