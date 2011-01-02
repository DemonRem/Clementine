/* This file is part of Clementine.
   Copyright 2010, David Sansome <me@davidsansome.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SCRIPT_H
#define SCRIPT_H

#include <QString>

#include <boost/scoped_ptr.hpp>

class LanguageEngine;
class ScriptInterface;

class Script {
public:
  Script(LanguageEngine* language, const QString& path,
         const QString& script_file, const QString& id);
  virtual ~Script();

  LanguageEngine* language() const { return language_; }
  const QString& path() const { return path_; }
  const QString& script_file() const { return script_file_; }
  const QString& id() const { return id_; }
  ScriptInterface* interface() const { return interface_.get(); }

  virtual bool Init() = 0;
  virtual bool Unload() = 0;

protected:
  boost::scoped_ptr<ScriptInterface> interface_;

private:
  Q_DISABLE_COPY(Script);

  LanguageEngine* language_;
  QString path_;
  QString script_file_;
  QString id_;
};

#endif // SCRIPT_H
